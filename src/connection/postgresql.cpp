/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

// TODO: Add logging feature

#include "postgresql.hpp"

#include <exception>
#include <string>

#include "base.hpp"           // BaseConnection
#include "nlohmann/json.hpp"  // nlohmann::json
#include "pqxx/pqxx"          // pqxx::connection, pqxx::work
#include "response.hpp"       // Response
#include "utils.hpp"          // utils::join, utils::readFile

using string = std::string;
using Json = nlohmann::json;
using UserData = nlohmann::json;

PostgreSQLConnection::PostgreSQLConnection(const Json &config)
    : BaseConnection(config) {
  this->_connection_type = PostgreSQL;
  this->table_name = this->db_config["table.name"].get<string>();
}

PostgreSQLConnection::~PostgreSQLConnection() {}

Response PostgreSQLConnection::open() {
  try {
    /**
     * Connection string requires space separated key value pairs. For example:
     *    key1=value1 key2=value2
     *
     * Hence utils::join() is used to make key value pairs in such manner from
     * a JSON key value pairs.
     */
    const auto &connection_string =
      utils::join(/* object */ this->db_config["connection.string"],
                  /* delimiter */ " ",
                  /* sub_delimiter */ "=");

    // Connecting to the PostgreSQL socket.
    this->connection =
      pqxx::connection(/* connection_string */ connection_string);
  }
  catch (const std::exception &error) {
    return Response(PROGRAM_FAILURE);
  }

  return Response();
}

Response PostgreSQLConnection::close() {
  try {
    this->connection.close();
  }
  catch (const std::exception &error) {
    return Response(PROGRAM_FAILURE);
  }

  return Response();
}

Response PostgreSQLConnection::initializeAuthStructure() {
  try {
    auto work = pqxx::work(/* connection */ this->connection);

    /**
     * Running initialization scripts from the file specified in
     * "table.initializer". This gives flexibility to both developers and the
     * program itself to dynamically operate with the database.
     */
    const auto &initialization_script =
      utils::readFile(/* file_name */
                      this->db_config["table.initializer"].get<string>());

    work.exec(/* query */ initialization_script);
    work.commit();
  }
  catch (const pqxx::sql_error &error) {
    return Response(QUERY_FAULT);
  }
  // Failures that are encountered by the program itself:
  catch (const std::exception &error) {
    return Response(PROGRAM_FAILURE);
  }

  return Response();
}

Response PostgreSQLConnection::destroyAuthStructure() {
  try {
    auto work = pqxx::work(/* connection */ this->connection);

    // Same as the "table.initializer"
    const auto &destruction_script =
      utils::readFile(/* file_name */
                      this->db_config["table.destroyer"].get<string>());

    work.exec(/* query */ destruction_script);
    work.commit();
  }
  catch (const pqxx::sql_error &error) {
    return Response(QUERY_FAULT);
  }
  // Failures that are encountered by the program itself:
  catch (const std::exception &error) {
    return Response(PROGRAM_FAILURE);
  }

  return Response();
}

Response PostgreSQLConnection::wipeAlldata() {
  // TODO(anyone): Implement this method
  return Response();
}

Response PostgreSQLConnection::addUser(const UserData &user_data) {
  try {
    auto columns = string();
    auto values = string();

    /**
     * Preparing data to insert into the table specified in table_name aka
     * "table.name" in PostgreSQL configuration.
     * Here, columns are for example: email, password, etc. and values are
     * collected from the corresponding column in user_data. For example,
     * consider the data was passed into user_date is:
     *   {
     *     "email": "example@email.com",
     *     "password": "very_strong_password"
     *   }
     *
     * This JSON data will be converted into this:
     * columns = "email, password";
     * values = "'example@email.com', 'very_strong_password'";
     */

    for (auto i = user_data.begin(); i != user_data.end(); i++) {
      if (i != user_data.begin() && i != user_data.end()) {
        // Separating each column names with ", ".
        columns.append(", ");

        // Separating each column values with ", ".
        values.append(", ");
      }

      // Use keys of JSON data as column names.
      columns.append(i.key());

      /**
       * Use values of each JSON data as column values with values wrapped by
       * single quotes (').
       */
      values.append("'" + i.value().get<string>() + "'");
    }

    // Inserting the data.
    auto work = pqxx::work(/* connection */ this->connection);

    // TODO(anyone): Insert distinct values
    work.exec(/* query */
              "INSERT INTO " + this->table_name + "(" + columns + ")" +
              " VALUES " + "(" + values + ")");
    work.commit();
  }
  catch (const pqxx::sql_error &error) {
    return Response(QUERY_FAULT);
  }
  // Failures that are encountered by the program itself:
  catch (const std::exception &error) {
    return Response(PROGRAM_FAILURE);
  }

  return Response();
}

Response PostgreSQLConnection::deleteUser(const Json &query) {
  try {
    auto work = pqxx::work(/* connection */ this->connection);
    work.exec(/* query */
              "DELETE FROM " + this->table_name + " WHERE " +
              utils::join(/* object */ query,
                          /* delimiter */ " AND ",
                          /* sub_delimiter */ " = ",
                          /* key_wrapper */ "",
                          /* value_wrapper */ "'"));
    work.commit();
  }
  catch (const pqxx::sql_error &error) {
    return Response(QUERY_FAULT);
  }
  catch (const std::exception &error) {
    return Response(PROGRAM_FAILURE);
  }

  return SUCCESS;
}

Response PostgreSQLConnection::updateUser(const Json &queries,
                                          const UserData &user_data) {
  try {
    const auto &updates = utils::join(/* object */ user_data,
                                      /* delimiter */ ", ",
                                      /* sub_delimiter */ " = ",
                                      /* key_wrapper */ "",
                                      /* value_wrapper */ "'");

    auto work = pqxx::work(/* connection */ this->connection);
    work.exec(/* query */
              "UPDATE " + this->table_name + " SET " + updates + " WHERE " +
              utils::join(/* object */ queries,
                          /* delimiter */ " AND ",
                          /* sub_delimiter */ " = ",
                          /* key_wrapper */ "",
                          /* value_wrapper */ "'"));

    work.commit();
  }
  catch (const pqxx::sql_error &error) {
    return Response(QUERY_FAULT);
  }
  catch (const std::exception &error) {
    return Response(PROGRAM_FAILURE);
  }

  return Response();
}

Response PostgreSQLConnection::queryUser(const Json &queries) {
  auto response = Response();

  try {
    auto data = Json({});

    auto work = pqxx::work(/* connection */ this->connection);
    const auto &row =
      work.exec(/* query */ "SELECT * FROM " + this->table_name + " WHERE " +
                utils::join(/* object */ queries,
                            /* delimiter */ " AND ",
                            /* sub_delimiter */ " = ",
                            /* key_wrapper */ "",
                            /* value_wrapper */ "'"));

    /**
     * None of the column values should be null. If there's null value from any
     * column then program should break out.
     */
    if (row[0][0].is_null()) {
      return Response(FAIL);
    }

    for (int i = 0; i < row.columns(); i++) {
      /**
       * Storing column names as JSON object keys and column values as values
       * of the keys.
       *
       * Here, name() method returns the name of column and c_str() method
       * returns the value of that corresponding column. Json takes this data
       * and then converts it into
       *  {
       *    "column2": "column_value1",
       *    "column1": "column_value2"
       *  }
       */
      data.push_back({row[0][i].name(), row[0][i].c_str()});
    }

    response.data = data;
  }
  catch (const pqxx::sql_error &error) {
    response.status_code = QUERY_FAULT;
  }
  catch (const std::exception &error) {
    response.status_code = PROGRAM_FAILURE;
  }

  return response;
}

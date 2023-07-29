/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "postgresql.hpp"

#include <exception>
#include <string>

#include "../utils.hpp"           // For utility functions
#include "auth/status_codes.hpp"  // For status codes
#include "base.hpp"               // For BaseConnection
#include "nlohmann/json.hpp"      // For JSON data structure
#include "pqxx/pqxx"              // For PostgreSQL database driver

using Json = nlohmann::json;
using UserData = nlohmann::json;

PostgreSQLConnection::PostgreSQLConnection(const Json &config)
    : BaseConnection(config) {
  this->_connection_type = PostgreSQL;
  this->table_name = this->config["table.name"].get<std::string>();
}

PostgreSQLConnection::~PostgreSQLConnection() {}

Status PostgreSQLConnection::open() {
  // Connecting to the PostgreSQL socket.
  this->connection = pqxx::connection(
    utils::join(/* object */ this->config["connection.string"],
                /* delimiter */ " ",
                /* sub_delimiter */ "="));

  return SUCCESS;
}

Status PostgreSQLConnection::close() {
  this->connection.close();
  return SUCCESS;
}

Status PostgreSQLConnection::initializeAuthStructure() {
  auto work = pqxx::work(this->connection);

  work.exec(
    utils::readFile(this->config["table.initializer"].get<std::string>()));
  work.commit();

  return SUCCESS;
}

Status PostgreSQLConnection::destroyAuthStructure() {
  auto work = pqxx::work(this->connection);

  work.exec(
    utils::readFile(this->config["table.destroyer"].get<std::string>()));
  work.commit();

  return SUCCESS;
}

Status PostgreSQLConnection::wipeAlldata() {
  return SUCCESS;
}

Status PostgreSQLConnection::addUser(const UserData &user_data) {
  auto work = pqxx::work(this->connection);

  auto columns = std::string();
  auto values = std::string();

  for (auto i = user_data.begin(); i != user_data.end(); i++) {
    if (i != user_data.begin() && i != user_data.end()) {
      columns.append(", ");
      values.append(", ");
    }
    columns.append(i.key());
    values.append("'" + i.value().get<std::string>() + "'");
  }

  work.exec("insert into " + this->table_name + "(" + columns + ")" +
            " values " + "(" + values + ")");
  work.commit();

  return SUCCESS;
}

Status PostgreSQLConnection::deleteUser(const Json &identifiers) {
  auto work = pqxx::work(this->connection);

  work.exec("delete from " + this->table_name + " where " +
            utils::join(/* object */ identifiers,
                        /* delimiter */ " and ",
                        /* sub_delimiter */ " = ",
                        /* key_wrapper */ "",
                        /* value_wrapper */ "'"));
  work.commit();

  return SUCCESS;
}

Status PostgreSQLConnection::updateUser(const Json &identifiers,
                                        const UserData &user_data) {
  auto work = pqxx::work(this->connection);
  auto updates = utils::join(/* object */ user_data,
                             /* delimiter */ ", ",
                             /* sub_delimiter */ " = ",
                             /* key_wrapper */ "",
                             /* value_wrapper */ "'");

  work.exec("update " + this->table_name + " set " + updates + " where " +
            utils::join(/* object */ identifiers,
                        /* delimiter */ " and ",
                        /* sub_delimiter */ " = ",
                        /* key_wrapper */ "",
                        /* value_wrapper */ "'"));

  work.commit();

  return SUCCESS;
}

UserData PostgreSQLConnection::queryUser(const Json &identifiers) {
  auto data = Json({});

  try {
    auto work = pqxx::work(this->connection);
    auto row = work.exec1("select * from " + this->table_name + " where " +
                          utils::join(/* object */ identifiers,
                                      /* delimiter */ " and ",
                                      /* sub_delimiter */ " = ",
                                      /* key_wrapper */ "",
                                      /* value_wrapper */ "'"));

    for (const auto &column : row) {
      data += {column.name(), column.c_str()};
    }
  }
  catch (const std::exception &error) {
  }

  return data;
}

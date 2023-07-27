/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "postgresql.hpp"

#include <string>
#include <string_view>

#include "../utils.hpp"       // For utility functions
#include "base.hpp"           // For BaseConnection
#include "nlohmann/json.hpp"  // For JSON data structure
#include "pqxx/pqxx"          // For PostgreSQL database driver
#include "status.hpp"         // For status codes

using Json = nlohmann::json;
using UserData = nlohmann::json;

PostgreSQLConnection::PostgreSQLConnection(const Json &config)
    : BaseConnection(config) {
  this->_connection_type = PostgreSQL;
  this->table_name = this->config["table.name"].get<std::string>();
}

PostgreSQLConnection::~PostgreSQLConnection() {}

Status PostgreSQLConnection::open() {
  auto connection_string = std::string();
  auto pg_config = &this->config["connection.string"];

  /**
   * To convert {"key": "value"} to key=value because pqxx::connection
   * need to set options.
   */
  for (auto i = pg_config->begin(); i != pg_config->end(); i++) {
    connection_string += i.key() + "=" + i.value().get<std::string>() + " ";
  }

  // Connecting to the PostgreSQL socket.
  this->connection = pqxx::connection(connection_string);

  return SUCCESS;
}

Status PostgreSQLConnection::close() {
  this->connection.close();
  return SUCCESS;
}

Status PostgreSQLConnection::initializeAuthStructure() {
  auto work = pqxx::work(this->connection);

  work.exec(
    utils::ReadFile(this->config["table.initializer"].get<std::string>()));
  work.commit();

  return SUCCESS;
}

Status PostgreSQLConnection::destroyAuthStructure() {
  auto work = pqxx::work(this->connection);

  work.exec(
    utils::ReadFile(this->config["table.destroyer"].get<std::string>()));
  work.commit();

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

Status PostgreSQLConnection::updateUser(std::string_view id,
                                        const UserData &user_data) {
  auto work = pqxx::work(this->connection);
  auto pairs = std::string();

  for (auto i = user_data.begin(); i != user_data.end(); i++) {
    if (i != user_data.begin() && i != user_data.end()) {
      pairs.append(", ");
    }
    pairs.append(i.key() + " = " + "'" + i.value().get<std::string>() + "'");
  }

  work.exec("update " + this->table_name + " set " + pairs +
            " where id = " + std::string(id));

  work.commit();

  return SUCCESS;
}

Status PostgreSQLConnection::deleteUser(std::string_view id) {
  auto work = pqxx::work(this->connection);

  work.exec("delete from " + this->table_name +
            " where id = " + std::string(id));
  work.commit();

  return SUCCESS;
}

Status PostgreSQLConnection::wipeAlldata() {
  return SUCCESS;
}

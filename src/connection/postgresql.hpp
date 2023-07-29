/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_CONNECTION_POSTGRESQL_HPP_
#define SRC_CONNECTION_POSTGRESQL_HPP_

#include <string>

#include "base.hpp"           // For BaseConnection
#include "nlohmann/json.hpp"  // For JSON data structure
#include "pqxx/pqxx"          // For PostgreSQL database driver

using Json = nlohmann::json;
using UserData = nlohmann::json;

class PostgreSQLConnection: public BaseConnection {
 private:
  /**
   * By default PostgreSQL tries to find dbname by user's name which throws
   * an exception. To prevent this unexpected behavior, set the dbname to
   * postgres. Since this dbname exists since PostgreSQL is installed.
   *
   * TODO: Please find a better way to do this.
   */
  pqxx::connection connection {"dbname=postgres"};
  std::string table_name;

 public:
  explicit PostgreSQLConnection(const Json &config);
  ~PostgreSQLConnection();

  Status open();
  Status close();

  Status initializeAuthStructure();
  Status destroyAuthStructure();

  Status addUser(const UserData &user_data);
  Status updateUser(const Json &condition, const UserData &user_data);
  Status deleteUser(const Json &condition);
  UserData queryUser(const Json &identifiers);
  Status wipeAlldata();
};

#endif  // SRC_CONNECTION_POSTGRESQL_HPP_

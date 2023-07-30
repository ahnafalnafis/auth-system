/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_CONNECTION_POSTGRESQL_HPP_
#define SRC_CONNECTION_POSTGRESQL_HPP_

#include <string>

#include "auth/response.hpp"  // Response
#include "base.hpp"           // BaseConnection
#include "nlohmann/json.hpp"  // nlohmann::json
#include "pqxx/pqxx"          // pqxx::connection

using string = std::string;
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

  /**
   * Name of the table in which user's authentication related data will be
   * stored into.
   */
  string table_name;

 public:
  explicit PostgreSQLConnection(const Json &config);
  ~PostgreSQLConnection();

  Response open();
  Response close();

  Response initializeAuthStructure();
  Response destroyAuthStructure();
  Response wipeAlldata();

  Response addUser(const UserData &user_data);
  Response deleteUser(const Json &queries);
  Response updateUser(const Json &queries, const UserData &user_data);

  Response queryUser(const Json &queries);
};

#endif  // SRC_CONNECTION_POSTGRESQL_HPP_

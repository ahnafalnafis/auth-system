/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_DB_CLIENTS_CONNECTION_HPP_
#define SRC_DB_CLIENTS_CONNECTION_HPP_

#include <cstdint>
#include <pqxx/pqxx>  // PostgreSQL driver
#include <string>
#include <string_view>

#include "nlohmann/json.hpp"

// Status codes:
enum Status : uint16_t { SUCCESS, FAIL, DB_IS_NOT_CONFIGURED };

// Supported databases:
enum DBTypes : uint16_t { PostgreSQL };

struct UserData {
  std::string id;
  std::string password;
};

/* * This class provides functions for each individual database connection class
 * to implement
 * */
class Connection {
 protected:
  /* *
   * Make sure the Connection object knows what kind of database it's
   * connected to.
   * */

  DBTypes _connection_type;

 public:
  Connection();
  virtual ~Connection();

  DBTypes getConnectionType();

  // Connection functions.
  virtual Status open(const nlohmann::json &config) = 0;
  virtual Status close() = 0;

  // Functions for managing underlying user data structures.
  virtual Status initializeAuthStructure() = 0;
  virtual Status destroyAuthStructure() = 0;

  // Functions for managing user data in the database.
  virtual Status addUser(const UserData &user_data) = 0;
  virtual Status updateUser(const UserData &user_data) = 0;
  virtual Status deleteUser(std::string_view id) = 0;
  UserData queryByID(std::string_view id) const;
  virtual Status wipeAlldata() = 0;
};

class PostgreSQLConnection : public Connection {
 private:
  // By default PostgreSQL tries to find dbname by user's name which throws an
  // exception. To prevent this unexpected behavior, set the dbname to
  // postgres. Since this dbname exists since PostgreSQL is installed.
  //
  // TODO: Please find a better way to do this.
  pqxx::connection connection{"dbname=postgres"};

 public:
  PostgreSQLConnection();
  ~PostgreSQLConnection();

  Status open(const nlohmann::json &config);
  Status close();
  Status initializeAuthStructure();
  Status destroyAuthStructure();

  Status addUser(const UserData &user_data);
  Status updateUser(const UserData &user_data);
  Status deleteUser(std::string_view id);
  Status wipeAlldata();
};

#endif  // SRC_DB_CLIENTS_CONNECTION_HPP_

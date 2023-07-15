/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_DB_CLIENTS_CONNECTION_HPP_
#define SRC_DB_CLIENTS_CONNECTION_HPP_

#include <cstdint>
#include <string>
#include <string_view>

// Status codes:
enum Status : uint16_t { SUCCESS, FAIL };

// Supported databases:
enum DBTypes : uint16_t { MongoDB, PostgreSQL };

struct UserData {
  std::string id;
  std::string password;
  // TODO(ahnafalnafis): implement date_created
};

/* *
 * This class provides functions for each individual database connection class
 * to implement
 * */
class Connection {
 protected:
  /* *
   * Make sure the Connection object knows what kind of database it's
   * connected to.
   * */

  DBTypes _connection_type;
  std::string db_file;

 public:
  Connection();
  virtual ~Connection();

  virtual DBTypes getConnectionType() = 0;

  // Connection functions.
  virtual Status openConnection() = 0;
  virtual Status closeConnection() = 0;

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

#endif  // SRC_DB_CLIENTS_CONNECTION_HPP_

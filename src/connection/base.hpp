/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_CONNECTION_BASE_HPP_
#define SRC_CONNECTION_BASE_HPP_

#include <cstdint>  // uint16_t

#include "auth/response.hpp"  // Response
#include "nlohmann/json.hpp"  // nlohmann::json

using Json = nlohmann::json;
using UserData = nlohmann::json;

// Supported databases:
enum DBType : uint16_t { PostgreSQL };

/**
 * This class provides functions for each individual database connection class
 * to implement
 */
class BaseConnection {
 protected:
  /**
   * Make sure the Connection object knows what kind of database it's
   * connected to.
   */

  DBType _connection_type;
  Json db_config;

 public:
  explicit BaseConnection(const Json &config);
  virtual ~BaseConnection();

  DBType getConnectionType() const;

  // Connection functions.
  virtual Response open() = 0;
  virtual Response close() = 0;

  // Functions for managing underlying user data structures.
  virtual Response initializeAuthStructure() = 0;
  virtual Response destroyAuthStructure() = 0;
  virtual Response wipeAlldata() = 0;

  // Functions for managing user data in the database.
  virtual Response addUser(const UserData &user_data) = 0;
  virtual Response deleteUser(const Json &queries) = 0;
  virtual Response updateUser(const Json &queries,
                              const UserData &user_data) = 0;

  virtual Response queryUser(const Json &queries) = 0;
};

#endif  // SRC_CONNECTION_BASE_HPP_

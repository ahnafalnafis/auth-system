/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_CONNECTION_BASE_HPP_
#define SRC_CONNECTION_BASE_HPP_

#include <cstdint>

#include "nlohmann/json.hpp"  // For JSON data structure
#include "status.hpp"         // For Status codes

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
  Json config;

 public:
  explicit BaseConnection(const Json &config);
  virtual ~BaseConnection();

  DBType getConnectionType();

  // Connection functions.
  virtual Status open() = 0;
  virtual Status close() = 0;

  // Functions for managing underlying user data structures.
  virtual Status initializeAuthStructure() = 0;
  virtual Status destroyAuthStructure() = 0;

  // Functions for managing user data in the database.
  virtual Status addUser(const UserData &user_data) = 0;
  virtual Status updateUser(const Json &condition,
                            const UserData &user_data) = 0;
  virtual Status deleteUser(const Json &condition) = 0;
  virtual UserData queryUser(const Json &identifiers) = 0;
  virtual Status wipeAlldata() = 0;
};

#endif  // SRC_CONNECTION_BASE_HPP_

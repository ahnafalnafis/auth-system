/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_DB_CLIENTS_MOCK_MOCKCONNECTION_HPP_
#define SRC_DB_CLIENTS_MOCK_MOCKCONNECTION_HPP_

#include <cstdint>
#include <string_view>

#include "../connection.hpp"

class MockConnection : Connection {
 public:
  MockConnection();
  ~MockConnection();

  DBTypes getConnectionType();

  Status openConnection();
  Status closeConnection();

  Status initializeAuthStructure();
  Status destroyAuthStructure();

  Status addUser(const UserData &user_data);
  Status updateUser(const UserData &user_data);
  Status deleteUser(std::string_view id);
  UserData queryByID(std::string_view id) const;
  Status wipeAlldata();
};

#endif  // SRC_DB_CLIENTS_MOCK_MOCKCONNECTION_HPP_

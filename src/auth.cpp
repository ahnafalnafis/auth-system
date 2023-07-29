/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "auth.hpp"

#include <fstream>  // For ifstream

#include "auth/status_codes.hpp"  // For status codes
#include "connection.hpp"         // For BaseConnection
#include "nlohmann/json.hpp"      // For JSON data structure

using UserData = nlohmann::json;

auto config =
  nlohmann::json::parse(std::ifstream("./examples/postgres/config.json"),
                        /* callback */ nullptr,
                        /* allow_exceptions */ true,
                        /* ignore_comments */ true);

Status auth::Register(const UserData &user_data) {
  if (!config["database.configured"]) {
    return FAIL;
  }

  auto psqlc = PostgreSQLConnection(config["database.config"]["PostgreSQL"]);
  auto *connection = &psqlc;

  connection->open();
  connection->initializeAuthStructure();

  if (!connection->queryUser(user_data).empty()) {
    return FAIL;
  }

  connection->addUser(user_data);

  connection->close();
  return SUCCESS;
}

/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "auth.hpp"

#include <fstream>  // ifstream

#include "auth/response.hpp"  // Response
#include "connection.hpp"     // BaseConnection
#include "nlohmann/json.hpp"  // nlohmann::json

using Json = nlohmann::json;
using UserData = nlohmann::json;

// Load configuration from configuration file.
auto config = Json::parse(std::ifstream("./examples/postgres/config.json"),
                          /* callback */ nullptr,
                          /* allow_exceptions */ true,
                          /* ignore_comments */ true);

Response auth::Register(const UserData &user_data) {
  if (!config["database.configured"]) {
    return Response(UNCONFIGURED_DATABASE);
  }

  auto psqlc = PostgreSQLConnection(config["database.config"]["PostgreSQL"]);
  auto *connection = &psqlc;

  connection->open();
  connection->initializeAuthStructure();

  auto query = connection->queryUser(user_data);

  /**
   * If something wrong happen while querying user, simply return the status
   * code
   */
  if (query.status_code) {
    return Response(query.status_code);
  }

  connection->addUser(user_data);

  connection->close();

  return Response();
}

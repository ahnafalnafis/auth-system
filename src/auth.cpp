/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "auth.hpp"

#include <exception>
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

  try {
    auto psqlc = PostgreSQLConnection(config["database.config"]["PostgreSQL"]);
    auto *connection = &psqlc;

    connection->open();
    connection->initializeAuthStructure();

    auto query = connection->queryUser(user_data);

    /**
     * Simply return what is returned from queryUser() if it wasn't either
     * SUCCESS or FAIL.
     */
    if (query.status_code != SUCCESS && query.status_code != FAIL) {
      return Response(query.status_code);
    }
    else if (query.status_code == SUCCESS) {
      return Response(FAIL);
    }
    connection->addUser(user_data);

    connection->close();
  }
  catch (const std::exception &error) {
    return Response(PROGRAM_FAILURE);
  }

  return Response();
}

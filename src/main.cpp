/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "db_clients/connection.hpp"

int main(int argc, char *argv[]) {
  auto config = nlohmann::json::parse(std::ifstream("./examples/config.json"),
                                      /* callback */ nullptr,
                                      /* allow_exceptions */ true,
                                      /* ignore_comments */ true);

  PostgreSQLConnection psqlc;
  Connection *connection = &psqlc;
  connection->open(config);

  connection->close();
  return 0;
}

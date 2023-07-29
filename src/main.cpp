/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <fstream>
#include <iostream>

#include "connection.hpp"
#include "nlohmann/json.hpp"
#include "status.hpp"

int main(int argc, char *argv[]) {
  auto config =
    nlohmann::json::parse(std::ifstream("./examples/postgres/config.json"),
                          /* callback */ nullptr,
                          /* allow_exceptions */ true,
                          /* ignore_comments */ true);

  if (config["database.configured"]) {
    auto psqlc = PostgreSQLConnection(config["database.config"]["PostgreSQL"]);
    auto *connection = &psqlc;

    connection->open();
    connection->initializeAuthStructure();

    connection->addUser({{"email", "ahah"},
                         {"password", "asdkaksd"},
                         {"date_created", "2023-12-12 12:12:00"}});

    connection->updateUser({{"id", "3"}},
                           {{"email", "jdlkajsdklas"},
                            {"password", "asdkaksd"},
                            {"date_created", "2023-12-12 12:12:00"}});

    connection->deleteUser({{"id", "1"}});

    auto data = connection->queryUser({{"id", "3"}});
    std::cout << data << std::endl;

    connection->close();
  }

  return SUCCESS;
}

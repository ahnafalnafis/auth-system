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

    connection->addUser({{"email", "ahnafaknafis@gmail.com"},
                         {"password", "kaasdkj"},
                         {"date_created", "2022-01-12 06:01:40"}});

    connection->deleteUser("4");
    connection->updateUser("2",
                           {{"email", "nobody@nowhere.com"},
                            {"password", "nothing"},
                            {"date_created", "2022-01-12 08:01:40"}});

    connection->close();
  }

  return SUCCESS;
}

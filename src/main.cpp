/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <fstream>
#include <iostream>

#include "auth.hpp"
#include "connection.hpp"
#include "nlohmann/json.hpp"

int main(int argc, char *argv[]) {
  auto status = auth::Register({{"email", "ahnafalnafis@gmail.com"},
                                {"password", "very_strong_password"},
                                {"date_created", "2003-10-22 12:47:40"}});

  std::cout << status << std::endl;
  return 0;
}

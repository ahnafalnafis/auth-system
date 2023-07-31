/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <iostream>

#include "auth.hpp"  // auth::Register

int main(int argc, char *argv[]) {
  const auto &response =
    auth::Register(/* user_data */
                   {{"email", "ahnafalnafis@gmail.com"},
                    {"password", "very_strong_password"},
                    {"date_created", "2003-10-22 12:47:40"}});

  /**
   * List of status codes:
   *   0 = SUCCESS
   * 101 = FAIL
   * 102 = PROGRAM_FAILURE
   * 103 = SERVER_FAULT
   * 104 = DATABASE_FAULT
   * 105 = QUERY_FAULT
   * 106 = UNCONFIGURED_DATABASE
   */
  std::cout << response.status_code << std::endl;

  return 0;
}

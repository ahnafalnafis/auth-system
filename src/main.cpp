/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <iostream>

#include "auth.hpp"  // auth::Register

int main(int argc, char *argv[]) {
  const auto response =
    auth::Register(/* user_data */ {{"email", "ahnafalnafis@gmail.com"},
                                    {"password", "very_strong_password"},
                                    {"date_created", "2003-10-22 12:47:40"}});

  std::cout << response.status << std::endl;
  return 0;
}

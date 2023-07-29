/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef AUTH_HPP
#define AUTH_HPP

#include "auth/status_codes.hpp"  // For status codes
#include "nlohmann/json.hpp"      // For JSON data structure

using UserData = nlohmann::json;

namespace auth {

  Status Login(const UserData &user_data);
  Status Register(const UserData &user_data);

}  // namespace auth

#endif

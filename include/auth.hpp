/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef INCLUDE_AUTH_HPP_
#define INCLUDE_AUTH_HPP_

#include "auth/response.hpp"  // Response
#include "nlohmann/json.hpp"  // nlohmann::json

using UserData = nlohmann::json;

namespace auth {

  Response Login(const UserData &user_data);
  Response Register(const UserData &user_data);

}  // namespace auth

#endif  // INCLUDE_AUTH_HPP_

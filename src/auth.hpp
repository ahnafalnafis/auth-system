/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_AUTH_HPP_
#define SRC_AUTH_HPP_

#include "nlohmann/json.hpp"  // nlohmann::json
#include "response.hpp"       // Response

using UserData = nlohmann::json;

namespace auth {

  Response Login(const UserData &user_data);
  Response Register(const UserData &user_data);

}  // namespace auth

#endif  // SRC_AUTH_HPP_

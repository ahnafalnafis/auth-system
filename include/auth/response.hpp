/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef INCLUDE_AUTH_RESPONSE_HPP_
#define INCLUDE_AUTH_RESPONSE_HPP_

#include <cstdint>  // uint16_t
#include <string>

#include "nlohmann/json.hpp"  // nlohmann::json

// Status codes:
enum _status_code : uint16_t {
  SUCCESS,
  FAIL = 101,
  SERVER_FAULT,
  DATABASE_FAULT,
  QUERY_FAULT,
  UNCONFIGURED_DATABASE,
  USER_EXISTS
};

class Response {
 public:
  Response(_status_code status_code = SUCCESS, nlohmann::json data = nullptr)
      : status_code(status_code), data(data) {}

  _status_code status_code;
  nlohmann::json data;
};

#endif  // INCLUDE_AUTH_RESPONSE_HPP_

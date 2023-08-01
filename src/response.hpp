/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef INCLUDE_AUTH_RESPONSE_HPP_
#define INCLUDE_AUTH_RESPONSE_HPP_

#include <cstdint>  // uint16_t
#include <string>

#include "nlohmann/json.hpp"  // nlohmann::json

using UserData = nlohmann::json;

// Status codes:
enum StatusCode : uint16_t {
  SUCCESS,
  FAIL = 101,
  PROGRAM_FAILURE,
  SERVER_FAULT,
  DATABASE_FAULT,
  QUERY_FAULT,
  UNCONFIGURED_DATABASE
};

struct Response {
  StatusCode status_code;
  nlohmann::json data;

  Response(const StatusCode status_code = SUCCESS,
           const UserData data = nullptr)
      : status_code(status_code), data(data) {}
};

#endif  // INCLUDE_AUTH_RESPONSE_HPP_

/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_RESPONSE_HPP_
#define SRC_RESPONSE_HPP_

#include <cstdint>  // uint16_t
#include <string>

#include "nlohmann/json.hpp"  // nlohmann::json

using UserData = nlohmann::json;

/**
 * Status codes for internal Response object.
 * These status codes doesn't have any kind of relationship with HTTP Response
 * status codes. These status codes are only limited to this program.
 */
enum StatusCode : uint16_t {
  SUCCESS,
  FAIL = 101,
  PROGRAM_FAILURE,
  SERVER_FAULT,
  DATABASE_FAULT,
  QUERY_FAULT,
  UNCONFIGURED_DATABASE
};

/**
 * Almost like a HTTP Response object but aimed for internal works only.
 */
struct Response {
  StatusCode status;

  // Optional message along with the status code.
  std::string message;

  // data should only refer to the user data returned by any function or so.
  UserData data;

  Response(const StatusCode &status = SUCCESS,
           const std::string &message = "",
           const UserData &data = nullptr)
      : status(status), message(message), data(data) {}
};

#endif  // SRC_RESPONSE_HPP_

/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <string>
#include <string_view>

#include "nlohmann/json.hpp"  // nlohmann::json

using string = std::string;
using string_view = std::string_view;

namespace utils {

  string readFile(string_view file_name);

  // Joins annoying key value pairs together.
  string join(const nlohmann::json &object,
              string_view delimiter = "",
              string_view sub_delimiter = "",
              string_view key_wrapper = "",
              string_view value_wrapper = "");

}  // namespace utils

#endif  // SRC_UTILS_HPP_

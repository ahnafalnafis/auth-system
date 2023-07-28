/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <string>
#include <string_view>

#include "nlohmann/json.hpp"

namespace utils {

  std::string readFile(std::string_view file_name);

  // Joins annoying key value pairs together.
  std::string join(const nlohmann::json &object,
                   std::string_view delimiter = "",
                   std::string_view sub_delimiter = "",
                   std::string_view key_wrapper = "",
                   std::string_view value_wrapper = "");

}  // namespace utils

#endif  // SRC_UTILS_HPP_

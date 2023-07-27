/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <string>
#include <string_view>

namespace utils {

  std::string ReadFile(std::string_view file_name);

}  // namespace utils

#endif  // SRC_UTILS_HPP_

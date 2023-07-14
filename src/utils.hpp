/*
 * Copyright 2023 Ahnaf Al Nafis
 * License: MIT
 */

#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include "nlohmann/json.hpp"

namespace utils {

// To load configurations from configuration file.
nlohmann::json LoadConfig();

}  // namespace utils

#endif  // SRC_UTILS_HPP_

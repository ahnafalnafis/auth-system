/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "utils.hpp"

#include <fstream>

#include "nlohmann/json.hpp"

nlohmann::json utils::LoadConfig() {
  return nlohmann::json::parse(std::ifstream("./config.json"),
                               /* callback */ nullptr,
                               /* allow_exceptions */ true,
                               /*ignore_comments */ true);
}

/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "utils.hpp"

#include <fstream>
#include <string>
#include <string_view>

#include "nlohmann/json.hpp"

std::string utils::readFile(std::string_view file_name) {
  auto file = std::ifstream(std::string(file_name));
  auto content = std::string();

  if (file.is_open()) {
    auto tmp_line = std::string();

    while (std::getline(file, tmp_line)) {
      content += tmp_line + "\n";
    }

    file.close();
  }

  return content;
}

std::string utils::join(const nlohmann::json &object,
                        std::string_view delimiter,
                        std::string_view sub_delimiter,
                        std::string_view key_wrapper,
                        std::string_view value_wrapper) {
  auto string_data = std::string();

  for (auto it = object.begin(); it != object.end(); it++) {
    if (it != object.begin() && it != object.end()) {
      string_data.append(std::string(delimiter));
    }

    if (!key_wrapper.empty() || !value_wrapper.empty() ||
        !sub_delimiter.empty()) {
      string_data.append(
        std::string(key_wrapper) + it.key() + std::string(key_wrapper) +
        std::string(sub_delimiter) + std::string(value_wrapper) +
        std::string(it.value()) + std::string(value_wrapper));
    }
    else {
      string_data.append(it.value());
    }
  }
  return string_data;
}

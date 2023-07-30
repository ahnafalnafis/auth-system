/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "utils.hpp"

#include <fstream>
#include <string>
#include <string_view>

#include "nlohmann/json.hpp"  // nlohmann::json

using string = std::string;
using string_view = std::string_view;

string utils::readFile(string_view file_name) {
  auto content = string();

  try {
    auto file = std::ifstream(string(file_name));

    if (file.is_open()) {
      auto tmp_line = string();

      while (std::getline(file, tmp_line)) {
        content += tmp_line + "\n";
      }

      file.close();
    }
  }
  catch (const std::exception &error) {
  }

  return content;
}

string utils::join(const nlohmann::json &object,
                   string_view delimiter,
                   string_view sub_delimiter,
                   string_view key_wrapper,
                   string_view value_wrapper) {
  auto string_data = string();

  try {
    for (auto it = object.begin(); it != object.end(); it++) {
      if (it != object.begin() && it != object.end()) {
        string_data.append(string(delimiter));
      }

      if (!key_wrapper.empty() || !value_wrapper.empty() ||
          !sub_delimiter.empty()) {
        string_data.append(string(key_wrapper) + it.key() +
                           string(key_wrapper) + string(sub_delimiter) +
                           string(value_wrapper) + string(it.value()) +
                           string(value_wrapper));
      }
      else {
        string_data.append(it.value());
      }
    }
  }
  catch (const std::exception &error) {
  }

  return string_data;
}

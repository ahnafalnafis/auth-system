/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "utils.hpp"

#include <fstream>
#include <string>
#include <string_view>

std::string utils::ReadFile(std::string_view file_name) {
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

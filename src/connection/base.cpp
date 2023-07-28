/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "base.hpp"

#include "nlohmann/json.hpp"  // For JSON data structure

using Json = nlohmann::json;

BaseConnection::BaseConnection(const Json &config): config(config) {}

BaseConnection::~BaseConnection() {}

DBType BaseConnection::getConnectionType() {
  return this->_connection_type;
}

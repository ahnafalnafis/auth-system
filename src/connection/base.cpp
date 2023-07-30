/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "base.hpp"

#include "nlohmann/json.hpp"  // nlohmann::json

using Json = nlohmann::json;

BaseConnection::BaseConnection(const Json &config): db_config(config) {}

BaseConnection::~BaseConnection() {}

DBType BaseConnection::getConnectionType() const {
  return this->_connection_type;
}

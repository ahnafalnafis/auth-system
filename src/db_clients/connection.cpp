/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "connection.hpp"

#include <string_view>

Connection::Connection() {}
Connection::~Connection() {}
DBTypes Connection::getConnectionType() { return this->_connection_type; }

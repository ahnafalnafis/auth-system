/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "connection.hpp"

#include "../utils.hpp"

auto config = utils::LoadConfig();

Connection::Connection() { this->db_file = config["db_file"]; }
DBTypes Connection::getConnectionType() { return this->_connection_type; }

#include <exception>
#include <iostream>
#include <pqxx/pqxx>  // PostgreSQL driver
#include <string>
#include <string_view>

#include "connection.hpp"
#include "nlohmann/json.hpp"

PostgreSQLConnection::PostgreSQLConnection() {
  this->_connection_type = PostgreSQL;
}

PostgreSQLConnection::~PostgreSQLConnection(){};

Status PostgreSQLConnection::open(const nlohmann::json &config) {
  if (config["database.configured"]) {
    try {
      auto connection_string = std::string();
      auto pg_config =
          &config["database.config"]["PostgreSQL"]["connection.string"];

      // TODO: Find a better algorithm for this.
      for (auto it = pg_config->begin(); it != pg_config->end(); it++) {
        connection_string += it.key() + "=" + std::string(it.value()) + " ";
      }

      // Connecting to the postgresql socket.
      this->connection = pqxx::connection(connection_string);

    } catch (std::exception const &error) {
      std::cerr << error.what() << std::endl;
      return FAIL;
    }

    return SUCCESS;
  }

  return DB_IS_NOT_CONFIGURED;
}

Status PostgreSQLConnection::close() {
  this->connection.close();
  return SUCCESS;
}

Status PostgreSQLConnection::initializeAuthStructure() {
  // TODO(ahnafalnafis): Create user table if doesn't exists
  return SUCCESS;
}
Status PostgreSQLConnection::destroyAuthStructure() { return SUCCESS; }

Status PostgreSQLConnection::addUser(const UserData &user_data) {
  return SUCCESS;
}
Status PostgreSQLConnection::updateUser(const UserData &user_data) {
  return SUCCESS;
}
Status PostgreSQLConnection::deleteUser(std::string_view id) { return SUCCESS; }

Status PostgreSQLConnection::wipeAlldata() { return SUCCESS; }

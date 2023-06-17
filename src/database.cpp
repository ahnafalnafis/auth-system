#include "database.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using nlohmann::json;

Database::Database(std::string data_path) {
  this->data_path = data_path;

  std::ifstream data_file(this->data_path);
  this->data = json::parse(data_file);
}

void Database::save() {
  std::ofstream data_file(this->data_path);
  data_file << this->data;
}

void Database::createUser() {}
void Database::deleteUser() {}
bool Database::exists() { return false; }

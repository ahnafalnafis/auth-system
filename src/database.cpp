#include "database.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>

Database::Database(const std::string& data_file) : data_file(data_file) {
  std::ifstream file_content(data_file);
  data = nlohmann::json::parse(file_content);
}

void Database::save() {
  std::ofstream data_file(this->data_file);
  data_file << data;
}

void Database::createUser(const User& user) {
  if (exists(user)) {
    std::cout << "User already exists!\n";
  } else {
    nlohmann::json userData;
    userData["username"] = user.getUserName();
    userData["email"] = user.getEmail();
    userData["password"] = user.getPassword();

    data.push_back(userData);
    std::cout << "Account has been created successfully.\n";
  }
}

void Database::deleteUser(const User& user) {
  auto it = std::find_if(data.begin(), data.end(), [&user](const auto& userData) {
    return userData["email"] == user.getEmail();
  });

  if (it != data.end()) {
    data.erase(it);
  } else {
    std::cout << "User doesn't exist!\n";
  }
}

bool Database::exists(const User& user) const {
  return std::any_of(data.begin(), data.end(), [&user](const auto& userData) {
    return userData["email"] == user.getEmail();
  });
}

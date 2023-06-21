#include "database.h"

#include <fstream>
#include <iostream>

#include "utils.h"

Database::Database(std::string data_file) {
  this->data_file = data_file;

  std::ifstream file_content(this->data_file);
  this->data = nlohmann::json::parse(file_content);
}

void Database::save() {
  std::ofstream data_file(this->data_file);
  data_file << this->data;
}

void Database::createUser(User user) {
  nlohmann::json userData;

  if (exists(user)) {
    std::cout << "User already exists!\n";
  } else {
    userData["username"] = user.getUserName();
    userData["email"] = user.getEmail();
    userData["password"] = user.getPassword();

    this->data.push_back(userData);
    std::cout << "Account has been created successfully.\n";
  }
}

void Database::deleteUser(User user) {
  if (exists(user)) {
    utils::ForEach(this->data,
                   [&user, this](nlohmann::json::iterator i) mutable -> bool {
                     if (i.value()["email"] == user.getEmail()) {
                       this->data.erase(i);

                       return 1;
                     };

                     return 0;
                   });
  } else {
    std::cout << "User doesn't exist!\n";
  }
}

bool Database::exists(User user) {
  bool existence;

  utils::ForEach(
      this->data,
      [user, &existence](nlohmann::json::iterator i) mutable -> bool {
        existence = (i.value()["email"] == user.getEmail());

        return existence;
      });

  return existence;
}

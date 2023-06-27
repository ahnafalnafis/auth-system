#include "user.hpp"

#include <iostream>

User::User(std::string username, std::string email, std::string password) {
  this->username = username;
  this->email = email;
  this->password = password;
}

std::string User::getUserName(void) { return this->username; }
void User::setUserName(std::string username) {
  this->username = username;
  std::cout << "Username has been updated.\n";
}

std::string User::getEmail(void) { return this->email; }
void User::setEmail(std::string email) {
  this->email = email;
  std::cout << "Email has been updated.\n";
}

std::string User::getPassword(void) { return this->password; }
void User::setPassword(std::string password) {
  this->password = password;
  std::cout << "Password has been updated.\n";
}

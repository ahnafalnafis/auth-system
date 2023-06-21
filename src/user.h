/*
 * User class. It defines an user. It provides following features when you
 * instantiate it, such as:
 *  - Setting or getting username.
 *  - Setting or getting email.
 *  - Setting or getting password.
 *  - Get user data in JSON format (TODO)
 *
 *  Example:
 *  User ahnaf = User("ahnaf", "ahnaf@example.com", "it_is_secret");
 */

#ifndef USER_H
#define USER_H

#include <iostream>

class User {
 private:
  std::string username;
  std::string email;
  std::string password;

 public:
  User(std::string username, std::string email, std::string password);

  std::string getUserName(void);
  void setUserName(std::string username);

  std::string getEmail(void);
  void setEmail(std::string email);

  std::string getPassword(void);
  void setPassword(std::string password);

  // TODO:
  // json getData(void);
};

#endif

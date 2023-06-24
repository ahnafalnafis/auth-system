#include <iostream>

#include "database.h"
#include "user.h"
#include "utils.h"

int main(void) {
  Database db = Database("./database.json");

  char answer;
  std::string email, password;

  // Confirmation:
  std::cout << "Do you have an account? [y/n]: ";
  std::cin >> answer;

  std::cout << "Email: ";
  std::cin >> email;

  std::cout << "Password: ";
  std::cin >> password;

  User user = User("", email, password);

  if (answer == 'y') {
    if (!db.exists(user)) {
      std::cout << "Sorry, this account does not exist.\n";
    }
  } else {
    std::string username;

    std::cout << "Give a username: ";
    std::cin >> username;
    user.setUserName(username);

    db.createUser(user);
  }

  std::cout << "Successfully logged in.\n";
  db.save();
  return 0;
}

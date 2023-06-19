#include "database.h"
#include "user.h"
#include "utils.h"
#include <iostream>

int main(void) {
  Database db = Database(std::getenv("DATABASE"));
  User whoever = User("whoever", "whoever@nowhere.com", "nothing");

  db.createUser(whoever);

  db.save();
  return 0;
}

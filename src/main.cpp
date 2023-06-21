#include <iostream>

#include "database.h"
#include "user.h"
#include "utils.h"

int main(void) {
  Database db = Database("./database.json");
  User whoever = User("whoever", "whoever@nowhere.com", "nothing");

  db.deleteUser(whoever);

  db.save();
  return 0;
}

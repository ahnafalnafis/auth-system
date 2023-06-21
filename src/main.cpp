#include <iostream>

#include "database.h"
#include "user.h"
#include "utils.h"

int main(void) {
  Database db = Database("./database.json");

  /* *
   * TODO:
   * Finally, implement the login and registration process!
   * */

  db.save();
  return 0;
}

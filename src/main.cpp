#include "database.hpp"
#include <iostream>
#include <nlohmann/json.hpp>

using nlohmann::json;
using std::string;

/*
 * TODO:
 * Make an User object.
 * User integration in database.
 * */

int main(void) {
  Database db = Database();

  db.save();
  return 0;
}

#include <iostream>

// #include "database.hpp"
// #include "user.hpp"
// #include "utils.hpp"
#include "nlohmann/json.hpp"

int main(int argc, char **argv) {
  // Database db = Database("../example_db.json");
  // db.save();
  /* *
   * TODO:
   * Take user data from the header and implement login.
   * */
  nlohmann::json header;

  if (argc > 2) {
    std::cout << "Too many arguments." << std::endl;
    return 1;
  } else {
    header = nlohmann::json::parse(argv[1]);
  }

  return 0;
}

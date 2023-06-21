/* *
 * Database class, it loads the data from the database when it is instantiated
 * and provides functionalities like:
 *  - Creating a new user data in the database.
 *  - Deleting a user from the database.
 *  - Checking whether the user exists or not.
 *
 *  Example:
 *  User john = User("john", "john@example.com", "1234");
 *
 *  Database db = Database("/data/users.json");
 *  db.createUser(john);
 *
 *  db.save();
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <nlohmann/json.hpp>

#include "user.h"

class Database {
 private:
  std::string data_file;

 public:
  /* *
   * Data will be stored temporarily to this variable and the data will be
   * saved when the program exits.
   */
  nlohmann::json data;

  /* *
   * Constructor function:
   * Parameters:
   *  data_file - The file where the data will be stored into.
   */
  Database(std::string data_file);

  /* *
   * Saves the changes that are made to the data. At least, call the
   * function before the program exits. Otherwise, it may cause losing
   * valuable data.
   */
  void save(void);

  void createUser(User user);
  void deleteUser(User user);

  bool exists(User user);
};

#endif

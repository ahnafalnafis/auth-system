#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>
#include <stdint.h>

// Full list of databases supported by this project
enum DB_TYPES : uint8_t {

  MongoDB, 
  Mock

};

/* *
 * This struct will need to change once we formally define what user data will
 * be stored in the DB
 * */
struct UserData {
  std::string identifier;
  std::string password;
};

/* *
 * This class provides functions for each individual DB connection class to
 * implement
 * */
class Connection {
 public:
  /* *
   * Return types of these functions are subject to change, int is just most
   * basic choice
   * */

  // Connection functions
  virtual uint16_t openConnection() = 0;
  virtual uint16_t closeConnection() = 0;

  // Functions for managing underlying user data structures
  virtual uint16_t initializeAuthStructureInDB() = 0;
  virtual uint16_t destroyAuthStructureInDB() = 0;

  // Functions for managing user data in the DB
  virtual UserData queryByUniqueIdentifier(std::string identifier) = 0;
  virtual uint16_t addUserToDB(UserData userData) = 0;
  virtual uint16_t deleteUserFromDB(std::string identifier) = 0;
  virtual uint16_t wipeAllUserDataFromDB() = 0;

  virtual DB_TYPES getConnectionType() = 0;

  // Base case destructor
  virtual ~Connection() {};

 private:
  /* *
   * Make sure the connection object knows what kind of database it's
   * connected to
   * */

  DB_TYPES _connectionType;
};

#endif

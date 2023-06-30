#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>

// Supported databases:
enum DB_TYPES { MongoDB, JSON };

struct UserData {
  std::string id;
  std::string password;
};
/* *
 * NOTE: This struct will need to change once we formally define what user data
 * will be stored in the database
 * */

/* *
 * This class provides functions for each individual database connection class
 * to implement
 * */
class Connection {
 public:
  // Connection functions, returns whether the connection was succeed or not.
  virtual bool open() = 0;
  virtual bool close() = 0;

  /*
  // Functions for managing underlying user data structures
  virtual int initializeAuthStructureInDB() = 0;
  virtual int destroyAuthStructureInDB() = 0;

  virtual UserData queryByID(std::string id) = 0;
  */

  // Functions for managing user data in the database
  virtual bool create(UserData user_data);
  virtual bool remove(std::string id) = 0;
  virtual bool wipe() = 0;

 private:
  /* *
   * Make sure the connection object knows what kind of database it's
   * connected to
   * */

  DB_TYPES connection_type;
};

class JSONConnection : public Connection {
  bool open();
  bool close();
  bool create(UserData user_data);
  bool remove(std::string id);
  bool wipe();
};

#endif

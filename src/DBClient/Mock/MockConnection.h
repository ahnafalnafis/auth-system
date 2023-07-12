#ifndef MOCK_CONNECTION_HPP
#define MOCK_CONNECTION_HPP

#include "../connection.h"

class MockConnection : Connection {

public:
/* *
   * Return types of these functions are subject to change, int is just most
   * basic choice
   * */

    MockConnection();

    // Connection functions
    uint16_t openConnection();
    uint16_t closeConnection();

    // Functions for managing underlying user data structures
    uint16_t initializeAuthStructureInDB();
    uint16_t destroyAuthStructureInDB();

    // Functions for managing user data in the DB
    UserData queryByUniqueIdentifier(std::string identifier);
    uint16_t addUserToDB(UserData userData);
    uint16_t deleteUserFromDB(std::string identifier);
    uint16_t wipeAllUserDataFromDB();

    DB_TYPES getConnectionType();   

    // Base case destructor
    ~MockConnection() {};


private:

    DB_TYPES _connectionType;

};

#endif
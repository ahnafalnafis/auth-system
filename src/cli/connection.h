#include <string>

// Full list of databases supported by this project
enum DB_TYPES {

    MongoDB

}

// This struct will need to change once we formally define what user data will be stored in the DB
struct UserData {

    std::string identifier;
    std::string password;

};

// This class provides functions for each individual DB connection class to implement
class Connection {

    // Return types of these functions are subject to change, int is just most basic choice
    public: 

        // Connection functions
        virtual int openConnection () = 0;
        virtual int closeConnection () = 0;

        // Functions for managing underlying user data structures
        virtual int initializeAuthStructureInDB () = 0;
        virtual int destroyAuthStructureInDB () = 0;

        // Functions for managing user data in the DB
        virtual int queryByUniqueIdentifier ( std::string identifier ) = 0;
        virtual int addUserToDB ( UserData userData  );
        virtual int deleteUserFromDB ( std::string identifier ) = 0;
        virtual int wipeAllUserDataFromDB () = 0;

    private:

        // Make sure the connection object knows what kind of database it's connected to
        DB_TYPES connectionType;

}
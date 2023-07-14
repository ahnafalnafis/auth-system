#include <MockConnection.h>

#include <random>

// set
MockConnection::MockConnection() {

    _connectionType = DB_TYPES::Mock;

}

DB_TYPES MockConnection::getConnectionType() {
    return _connectionType;
}

// Return 1 on success and 0 on failure
uint16_t MockConnection::openConnection() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,1);
    return dist6(rng);
}

// Let closing connection always succeed
uint16_t MockConnection::closeConnection() {
    return 1;
}

// Return a random possible success value
uint16_t MockConnection::initializeAuthStructureInDB() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(-1,1);
    
    // Used to account for undefined behavior introduced by using a negative value in the dist6 range
    switch(dist6(rng)) {

        // Success
        case 1: 
            return 1;

        // Failure
        case 0: 
            return 0;

        // Other issue    
        default:
            return -1;
    }
}

// Return a random possible success value
uint16_t MockConnection::destroyAuthStructureInDB() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(-1,1);
    
    // Used to account for undefined behavior introduced by using a negative value in the dist6 range
    switch(dist6(rng)) {

        // Success
        case 1: 
            return 1;

        // Failure
        case 0: 
            return 0;

        // Other issue    
        default:
            return -1;
    }
}

// Return a UserData struct on success, or throw exception
UserData MockConnection::queryByUniqueIdentifier(std::string) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(-1,1);
    
    // Used to account for undefined behavior introduced by using a negative value in the dist6 range
    switch(dist6(rng)) {

        // Success
        case 1: 
            return {
                "username",
                "password_lol"
            };

        // Failure
        case 0: 
            throw std::exception();

        // Other issue    
        default:
            throw std::exception();
    }
}

// Return a random possible success value
uint16_t MockConnection::addUserToDB(UserData data) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(-1,1);
    
    // Used to account for undefined behavior introduced by using a negative value in the dist6 range
    switch(dist6(rng)) {

        // Success
        case 1: 
            return 1;

        // Failure
        case 0: 
            return 0;

        // Other issue    
        default:
            return -1;
    }
}

// Return a random possible success value
uint16_t MockConnection::deleteUserFromDB(std::string identifier) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(-1,1);
    
    // Used to account for undefined behavior introduced by using a negative value in the dist6 range
    switch(dist6(rng)) {

        // Success
        case 1: 
            return 1;

        // Failure
        case 0: 
            return 0;

        // Other issue    
        default:
            return -1;
    }
}

uint16_t MockConnection::wipeAllUserDataFromDB() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(-1,1);
    
    // Used to account for undefined behavior introduced by using a negative value in the dist6 range
    switch(dist6(rng)) {

        // Success
        case 1: 
            return 1;

        // Failure
        case 0: 
            return 0;

        // Other issue    
        default:
            return -1;
    }
}
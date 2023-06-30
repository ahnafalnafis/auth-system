#include "connection.hpp"

#include <iostream>

bool JSONConnection::open() { return true; }
bool JSONConnection::close() { return true; }
bool JSONConnection::create(UserData user_data) { return true; }
bool JSONConnection::remove(std::string id) { return true; }
bool JSONConnection::wipe() { return true; }

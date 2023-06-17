#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <nlohmann/json.hpp>

class Database {
private:
  std::string data_path;

public:
  nlohmann::json data;

  Database(std::string data_path = "./db.json");
  void save(void);

  void createUser();
  void deleteUser();
  bool exists();
};

#endif

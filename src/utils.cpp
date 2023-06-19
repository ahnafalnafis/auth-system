#include "utils.h"
#include <iostream>

void utils::ForEach(nlohmann::json &data,
                    std::function<bool(nlohmann::json::iterator)> callback) {

  bool ok;
  for (auto i = data.begin(); i != data.end(); ++i) {
    ok = callback(i);

    if (ok) {
      std::cout << "Okay\n";
      break;
    }
  }
};

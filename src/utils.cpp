#include "utils.h"

void utils::ForEach(nlohmann::json &data,
                    std::function<bool(nlohmann::json::iterator)> callback) {
  bool ok;
  for (auto i = data.begin(); i != data.end(); ++i) {
    ok = callback(i);
    if (ok) {
      break;
    }
  }
}

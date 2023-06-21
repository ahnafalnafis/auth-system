/*
 * This file contains some utilities.
 */

#ifndef UTILS_H
#define UTILS_H

#include <functional>
#include <nlohmann/json.hpp>

namespace utils {
void ForEach(nlohmann::json &data,
             std::function<bool(nlohmann::json::iterator)> callback);
}

#endif

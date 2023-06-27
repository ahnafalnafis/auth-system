/*
 * This file contains some utilities.
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <functional>

#include "nlohmann/json.hpp"

namespace utils {
/* *
 * ForEach function is used to iterate through a JSON data and meanwhile call
 * the callback function. While iterating through, ForEach function will pass
 * each iterator from the JSON data to the callback function. So that the
 * callback function can perform some operation with the iterator.
 * */

void ForEach(nlohmann::json &data,
             std::function<bool(nlohmann::json::iterator)> callback);
}  // namespace utils

#endif

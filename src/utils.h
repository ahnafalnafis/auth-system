/*
 * This file contains some utilities.
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>

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

namespace io {
/* *
 * Convenient Python-like C++ in input wrapper.
 * */
template <typename T>
T input(const std::string &prompt = "");
}  // namespace io

#endif

#include "utils.h"

#include <limits>

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

template <typename T>
T io::input(const std::string &prompt) {
  std::cout << prompt;

  T value;
  std::cin >> value;

  // Handle if the previous operation failed.
  if (!std::cin) {
    /* *
     * If the failure was because the input stream was closed, gently print a
     * new line and shutdown the program.
     * */
    if (std::cin.eof()) {
      std::cout << std::endl;
      exit(0);
    }

    // Set extraction operation to normal mode.
    std::cin.clear();
  }

  // Clear up until the enter key is pressed.
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return value;
};

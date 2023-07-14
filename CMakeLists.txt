cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

project(
  auth-system
  VERSION 0.0.2
  LANGUAGES CXX)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
file(GLOB CPP_FILES "${SRC_DIR}/*.cpp" "${SRC_DIR}/db_clients/*.cpp")
add_executable(authenticate ${CPP_FILES})

add_subdirectory(${LIB_DIR}/nlohmann_json)
target_link_libraries(authenticate PRIVATE nlohmann_json::nlohmann_json)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(authenticator VERSION 0.0.2)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

add_executable(authenticator ${SRC_DIR}/main.cpp)

add_subdirectory(${LIB_DIR}/nlohmann_json)
target_link_libraries(authenticator PRIVATE nlohmann_json::nlohmann_json)

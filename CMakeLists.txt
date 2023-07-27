cmake_minimum_required(VERSION 3.15)

# Compiler options:
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# Project:
project(
  auth-system
  VERSION 0.0.2
  LANGUAGES CXX)

# Declarations:
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(EXTERNAL_LIB_DIR ${PROJECT_SOURCE_DIR}/external)
set(EXECUTABLE_NAME auth)

# Executable:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(${EXECUTABLE_NAME})

# Sub directories:
add_subdirectory(${SRC_DIR})
add_subdirectory(${EXTERNAL_LIB_DIR}/libpqxx)

# Libraries:
target_link_libraries(${EXECUTABLE_NAME} PRIVATE pqxx)
include_directories(${EXTERNAL_LIB_DIR}/nlohmann_json/include)

# Include directories:
include_directories(include)

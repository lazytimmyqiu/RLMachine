cmake_minimum_required (VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project (RLMachine)

include_directories ("${PROJECT_SOURCE_DIR}/framework/common")
include_directories ("${PROJECT_SOURCE_DIR}/framework/base")
include_directories ("${PROJECT_SOURCE_DIR}/framework/context")

add_subdirectory(framework)

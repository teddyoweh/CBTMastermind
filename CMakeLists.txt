cmake_minimum_required(VERSION 3.10)

project(CBTApplication)
add_executable(CBTApplication src/main.cpp src/cbt_application.cpp src/question.cpp src/user.cpp src/utils.cpp)
target_include_directories(CBTApplication PRIVATE includes)
set_target_properties(CBTApplication PROPERTIES CXX_STANDARD 11)

 
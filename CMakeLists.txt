cmake_minimum_required(VERSION 3.12)
project(CBT_Application)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES
    main.cpp
    cbt_application.cpp
    includes/cbt_application.h
    includes/question.h
    includes/user.h
    includes/utils.h
)
add_executable(CBT_Application ${SOURCES})
target_include_directories(CBT_Application PRIVATE includes)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

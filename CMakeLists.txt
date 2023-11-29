cmake_minimum_required(VERSION 3.14)  

project(LeetCodeSolutions VERSION 1.0
        DESCRIPTION "LeetCode Solutions"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the solutions directory
set(SOLUTIONS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/solutions)
include_directories(${SOLUTIONS_DIR})

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(solutions)
add_subdirectory(tests)

# Add a custom target for cppcheck
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/cppcheck.stamp
    COMMAND cppcheck 
        --enable=warning,performance,portability,style --language=c++
        --std=c++20 --verbose --error-exitcode=1
        --platform=win64
        ${CMAKE_SOURCE_DIR}/solutions/*.hpp
        ${CMAKE_SOURCE_DIR}/tests/*.cpp
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/cppcheck.stamp
    COMMENT "Running cppcheck"
)

add_custom_target(cppcheck ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/cppcheck.stamp)

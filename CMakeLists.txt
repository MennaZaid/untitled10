cmake_minimum_required(VERSION 3.29)
project(untitled10)

set(CMAKE_CXX_STANDARD 20)

# Create a library from your palindrome code (EXCLUDE main.cpp)
add_library(palindrome_lib palindrome.cpp)

# Main executable (includes main.cpp separately)
add_executable(untitled10 main.cpp)
target_link_libraries(untitled10 PRIVATE palindrome_lib)

# Set up Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable (DO NOT include main.cpp here)
add_executable(example example.cpp palindrome.cpp)
target_link_libraries(example PRIVATE gtest gtest_main palindrome_lib pthread)  # Add pthread for stability

# Enable testing
enable_testing()
add_test(NAME example_test COMMAND example)

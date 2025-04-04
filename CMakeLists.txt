cmake_minimum_required(VERSION 3.29)
project(untitled10)

set(CMAKE_CXX_STANDARD 20)

# Create a library from your palindrome code
add_library(palindrome_lib palindrome.cpp
        main.cpp)

# Main executable that uses the library
add_executable(untitled10 main.cpp
        main.cpp)
target_link_libraries(untitled10 PRIVATE palindrome_lib)

# Test executable
add_executable(example example.cpp
        main.cpp
        main.cpp
        palindrome.cpp)

# Set up Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Link the test executable with Google Test and your palindrome library
target_link_libraries(example PRIVATE gtest gtest_main palindrome_lib)

# Enable testing
enable_testing()
add_test(NAME example_test COMMAND example)

cmake_minimum_required(VERSION 3.11)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_subdirectory(SnakeLibrary)
add_subdirectory(Snake)

enable_testing()

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.74 COMPONENTS unit_test_framework REQUIRED)

include_directories(
        SnakeLibrary/include
        ${Boost_INCLUDE_DIRS})

link_directories(${Boost_LIBRARY_DIR})

set (-Wall -Wpedantic -Wextra -Werror)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})


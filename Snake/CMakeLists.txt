cmake_minimum_required(VERSION 3.4)

project(Snake)

set(SOURCE_FILES src/main.cpp)

add_executable(Snake ${SOURCE_FILES})

target_include_directories(Snake PUBLIC include)

target_link_libraries(Snake SnakeLibrary
        ${wxWidgets_LIBRARIES})

enable_testing()
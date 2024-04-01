cmake_minimum_required(VERSION 3.4)
project(SnakeLibrary)

set(SOURCE_FILES
        src/Game.cpp include/Game.h include/Segment.h src/Segment.cpp src/Snake.cpp include/Snake.h src/Head.cpp include/Head.h src/Tail.cpp include/Tail.h src/Fruit.cpp include/Fruit.h src/CLIObserver.cpp include/CLIObserver.h src/Observer.cpp include/Observer.h src/Frame.cpp include/Frame.h src/ScoreManager.cpp include/ScoreManager.h src/GameException.cpp include/GameException.h)

add_library(SnakeLibrary ${SOURCE_FILES})

target_include_directories(SnakeLibrary PUBLIC include)

enable_testing()
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

target_link_libraries(SnakeLibrary ${wxWidgets_LIBRARIES})

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable(SnakeLibraryTest ../test/master.cpp ../test/SnakeTest.cpp ../test/ScoreManagerTest.cpp ../test/GameTest.cpp)

target_link_libraries(SnakeLibraryTest SnakeLibrary
        ${wxWidgets_LIBRARIES}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_test(SnakeLibraryTest1 SnakeLibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
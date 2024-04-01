#include "Game.h"
#include <boost/test/unit_test.hpp>



struct TestSuiteSnakeFixture {
    GamePtr gra;
    SnakePtr snake;
    int x = 7;
    int y = 7;

    TestSuiteSnakeFixture(){
        gra = std::make_shared<Game>(7,7);
        snake = gra->getSnake();
    }

    ~TestSuiteSnakeFixture(){

    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteSnake, TestSuiteSnakeFixture)

    BOOST_AUTO_TEST_CASE(SnakeConstructorTests)
    {
        std::pair<int, int> headLocation;
        headLocation = snake->getHead()->getLocation();
        BOOST_TEST(snake->getLength() == 3);
        BOOST_TEST(snake->getHead() != nullptr);
        BOOST_TEST(headLocation.first == x/2 + x%2);
        BOOST_TEST(headLocation.second == y/2 + y%2);
    }
    BOOST_AUTO_TEST_CASE(SnakeEatTest)
    {
        int size = snake->getLength();
        snake->eat();
        BOOST_TEST(snake->getLength() > size);
    }
    BOOST_AUTO_TEST_CASE(SnakeMoveTest)
    {
        std::pair<int, int> headLocation;
        headLocation = snake->getHead()->getLocation();
        snake->moveAll(up);
        BOOST_CHECK(snake->getHead()->getLocation().second == headLocation.second + 1);
        snake->moveAll(down);
        BOOST_CHECK(snake->getHead()->getLocation().second == headLocation.second + 2);
        snake->moveAll(left);
        BOOST_CHECK(snake->getHead()->getLocation().first == headLocation.first - 1);
    }
    BOOST_AUTO_TEST_CASE(ChangeDirectionTest)
    {
        direction dir = snake->getHead()->getD();
        snake->moveAll(down);
        BOOST_TEST(snake->getHead()->getD() == dir);
        snake->moveAll(right);
        BOOST_TEST(snake->getHead()->getD() == right);
        snake->moveAll(down);
        BOOST_TEST(snake->getHead()->getD() == down);
    }

BOOST_AUTO_TEST_SUITE_END()
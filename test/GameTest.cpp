#include "Game.h"
#include <boost/test/unit_test.hpp>



struct TestSuiteGameFixture {
    GamePtr gra;
    SnakePtr snake;
    int x = 7;
    int y = 7;

    TestSuiteGameFixture(){
        gra = std::make_shared<Game>(7,7);
        snake = gra->getSnake();
    }

    ~TestSuiteGameFixture(){

    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteGame, TestSuiteGameFixture)

    BOOST_AUTO_TEST_CASE(GameConstructorTests)
    {
        BOOST_TEST(gra->getXSize() == x);
        BOOST_TEST(gra->getYSize() == y);
        BOOST_TEST(gra->getTime() == 0);
    }
    BOOST_AUTO_TEST_CASE(FruitSpawnTest)
    {
        std::pair<int, int> fruitLocation;
        fruitLocation = gra->getFruit()->getLocation();
        BOOST_TEST_REQUIRE(fruitLocation.first <= x);
        BOOST_TEST_REQUIRE(fruitLocation.second <= y);

    }
    BOOST_AUTO_TEST_CASE(FullScoreTest)
    {
        for(int i = 0; i < x * y - 3; i++)
        {
            snake->eat();
        }
        BOOST_TEST(gra->checkWin() == 1);
    }
    BOOST_AUTO_TEST_CASE(EndGameTest)
    {
        snake->eat();
        snake->eat();
        snake->moveAll(up);
        snake->moveAll(left);
        snake->moveAll(down);
        snake->moveAll(right);
        BOOST_TEST(gra->checkCollision() == 1);
    }

BOOST_AUTO_TEST_SUITE_END()
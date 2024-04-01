#include "Game.h"
#include <boost/test/unit_test.hpp>
#include <fstream>



struct TestSuiteScoreManagerFixture {
    GamePtr gra;
    SnakePtr snake;
    ScoreManagerPtr manager;
    int x = 7;
    int y = 7;

    TestSuiteScoreManagerFixture(){
        gra = std::make_shared<Game>(x,y);
        snake = gra->getSnake();
        manager = gra->getScoreManager();
    }

    ~TestSuiteScoreManagerFixture(){

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteScoreManager, TestSuiteScoreManagerFixture)
    BOOST_AUTO_TEST_CASE(ScoreCountTest)
    {
        int score = manager->calculateScore();
        gra->increaseTime();
        gra->increaseTime();
        int score2 = score - 5 * gra->getTime();
        BOOST_TEST(manager->calculateScore() == score2);

    }
    BOOST_AUTO_TEST_CASE(SnakeLengthChangeScoreTest)
    {
        int score = manager->calculateScore();
        snake->eat();
        snake->eat();
        int score2 = score + 2 * 200;
        BOOST_TEST(manager->calculateScore() == score2);
        gra->increaseTime();
        score2 -= 5;
        BOOST_TEST(manager->calculateScore() == score2);
    }
	BOOST_AUTO_TEST_CASE(FileTests)
	{
		int score = manager->calculateScore();
		manager->writeScore();
		std::fstream plik;
		plik.open("Scores.txt");
		BOOST_TEST_REQUIRE(plik.is_open());
		std::string buff;
		getline(plik,buff,'\n');
		int wscore = std::stoi(buff);
		BOOST_TEST(wscore == score);
		plik.close();
		plik.open("Scores.txt",std::ios_base::app);
		int nscore = 99999999;
		plik << nscore;
		plik << '\n';
		plik << 4000000;
		plik << '\n';
		plik.close();
		ScoreManagerPtr man = manager;
		int hscore = man->getHighScore();
		BOOST_TEST(hscore == nscore);
	}

BOOST_AUTO_TEST_SUITE_END()
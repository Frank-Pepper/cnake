#include "ScoreManager.h"

int ScoreManager::getHighScore()
{
	return this->highScore;
}

int ScoreManager::findHighScore()
{
	try
	{
		std::fstream plik("Scores.txt",std::fstream::in | std::fstream::app);
		std::string s;
		int highscore = 0;
		if (!plik.is_open())
		{
			throw std::bad_exception();
		}
		while (getline(plik, s))
		{
			int cscore = stoi(s);
			if (cscore > highscore)
			{
				highscore = cscore;
			}
		}
		plik.close();
		return highscore;
	}
	catch (std::bad_exception & exception)
	{
		std::cerr << "Couldn't open scores file";
		return 0;
	}
}

void ScoreManager::writeScore()
{
	try
	{
		std::fstream plik;
		plik.open("Scores.txt", std::ios_base::app);
		if (!plik.is_open())
		{
			throw std::bad_exception();
		}
		int score = calculateScore();
		plik << score;
		plik << '\n';
		plik.close();
	}
	catch (std::bad_exception &exception)
	{
		std::cerr << "Couldn't open scores file";
		return;
	}
}

ScoreManager::ScoreManager(Game* game) : game(game)
{
    if(game == nullptr){
        throw GameException("Game is a nullptr");
    }
	this->highScore = findHighScore();
}

int ScoreManager::calculateScore()
{
	return ((game->getSnake()->getLength() * 200) - (game->getTime() * 5));
}
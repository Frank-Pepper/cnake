#include "Game.h"
#include "Snake.h"

Game::Game(int xSize, int ySize) : xSize(xSize), ySize(ySize), fruit(std::make_shared<Fruit>())
{
    if(xSize < 5)
	{
        throw GameException("X size of game is too small");
    }
    if(ySize < 5)
	{
        throw GameException("Y size of game is too small");
    }
    snake = std::make_shared<Snake>(this);
    scoreManager = std::make_shared<ScoreManager>(this);
	fruit = std::make_shared<Fruit>();
    spawnFruit();
}

const int Game::getXSize() const
{
    return xSize;
}

const int Game::getYSize() const
{
    return ySize;
}

const SnakePtr Game::getSnake() const
{
    return snake;
}

void Game::spawnFruit() {
    if (snake->getLength() == xSize * ySize) {
        fruit->setX(0);
        fruit->setY(0);
    } else {
        int x, y;
        bool flag = true;
        while (flag) {
            x = rand() % getXSize() + 1;
            y = rand() % getYSize() + 1;
            flag = snake->isTaken(x, y);
        }
        fruit->setX(x);
        fruit->setY(y);
    }
}

FruitPtr Game::getFruit()
{
    return fruit;
}

bool Game::checkWin()
{
    int area = this->xSize * this->ySize;
    if( this->getSnake()->getLength() == area )
        return true;
    return false;
}

int Game::getTime()
{
	return time;
}

const ScoreManagerPtr &Game::getScoreManager() const
{
	return scoreManager;
}

bool Game::checkCollision()
{
	std::pair<int, int> HeadLocation = snake->getHead()->getLocation();
	if(HeadLocation.first < 1 || HeadLocation.first > this->getXSize() || HeadLocation.second < 1 || HeadLocation.second > this->getYSize())
	{
		return true;
	}
	int flag = 0;
	for( auto segment : snake->getSegments())
	{
		if( segment->getLocation() == HeadLocation ){
			flag++;
			if( flag > 1)
				return true;
		}
	}
	std::pair<int, int> FruitLocation = this->getFruit()->getLocation();
	if( HeadLocation == FruitLocation )
	{
		snake->eat();
		return false;
	}
	return false;
}

void Game::increaseTime()
{
	this->time++;
}

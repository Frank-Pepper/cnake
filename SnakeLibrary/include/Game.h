#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include "Fruit.h"
#include "Snake.h"
#include "ScoreManager.h"
#include "GameException.h"


class ScoreManager;

class Observer;

typedef std::shared_ptr<Snake> SnakePtr;
typedef std::shared_ptr<Fruit> FruitPtr;
typedef std::shared_ptr<Observer> ObserverPtr;
typedef std::shared_ptr<ScoreManager> ScoreManagerPtr;

class Game {
private:
    int time = 0;
	int xSize;
    int ySize;
    FruitPtr fruit;
    SnakePtr snake;
	ScoreManagerPtr scoreManager;
public:
	const ScoreManagerPtr &getScoreManager() const;
    Game(int xSize, int ySize);
    const int getXSize() const;
    const int getYSize() const;
    const SnakePtr getSnake() const;
    void spawnFruit();
    FruitPtr getFruit();
    bool checkWin();
	int getTime();
	bool checkCollision();
	void increaseTime();
};


#endif //SNAKEGAME_GAME_H

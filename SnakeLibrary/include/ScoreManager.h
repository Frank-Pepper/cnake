#ifndef SNAKEGAME_SCOREMANAGER_H
#define SNAKEGAME_SCOREMANAGER_H

#include "Game.h"
#include <fstream>
#include <string>
#include <iostream>



class ScoreManager
{
private:
    Game* game;
	int highScore;
	int findHighScore();
public:
	int getHighScore();
	void writeScore();
	ScoreManager(Game* game);
	int calculateScore();
};


#endif //SNAKEGAME_SCOREMANAGER_H

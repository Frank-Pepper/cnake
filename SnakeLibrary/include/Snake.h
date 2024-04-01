#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <vector>
#include <memory>
#include "Segment.h"

class Game;

typedef std::shared_ptr<Segment> SegmentPtr;
typedef std::shared_ptr<Game> GamePtr;

class Snake{
private:
    int Length = 3;
    std::vector<SegmentPtr> segments;
    Game* game;

public:
    Snake(Game* gra_);
    int getLength();
    std::vector<SegmentPtr> &getSegments();
    SegmentPtr getHead();
    std::string getFullInfo();
    void eat();
    void moveAll(direction dir);
    void grow();

	bool isTaken(int x, int y);
};


#endif //SNAKEGAME_SNAKE_H

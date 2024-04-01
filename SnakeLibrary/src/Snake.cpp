#include "Snake.h"
#include "Segment.h"
#include "Game.h"
#include "Head.h"

Snake::Snake(Game* gra_) : game(gra_)
{
    segments.push_back(std::make_shared<Head>(game->getXSize() / 2+ game->getXSize()%2, game->getYSize() / 2 + game->getYSize()%2, up));
}

int Snake::getLength()
{
    return Length;
}

std::vector<SegmentPtr> &Snake::getSegments()
{
    return segments;
}

SegmentPtr Snake::getHead()
{
    return segments[0];
}

std::string Snake::getFullInfo()
{
    std::string data;
    for(auto segment: segments ){
        data += segment->getInfo();
    }
    data += "\n";
    return data;
}

void Snake::eat() {
    Length++;
    game->spawnFruit();
}

void Snake::moveAll(direction dir)
{
    direction D;
    for( auto segment : segments )
	{
        D = segment->getD();
        segment->move(dir);
        dir = D;
    }
    if( Length > segments.size() )
	{
        grow();
    }
}

void Snake::grow() {
    SegmentPtr tail = segments[segments.size()-1];
    int xPosition = tail->getLocation().first, yPosition = tail->getLocation().second;
    direction dir = tail->getD();
    if( dir % 2 ){
        yPosition -= (dir - 2);
    }
    else {
        xPosition -= dir - 3;
    }
    segments.push_back(std::make_shared<Head>(xPosition, yPosition, dir));
}

bool Snake::isTaken(int x, int y) {
    for (auto segment : segments) {
        if (segment->getLocation().first == x && segment->getLocation().second == y) {
            return true;
        }
    }
    return false;
}

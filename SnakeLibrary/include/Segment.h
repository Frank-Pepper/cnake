#ifndef SNAKEGAME_SEGMENT_H
#define SNAKEGAME_SEGMENT_H

#include <utility>
#include <string>

enum direction
{
    up=3,
    right=4,
    down=1,
    left=2
};

class Segment
{
private:
    int x;
    int y;
    direction D;
public:
    Segment(int x, int y, direction d);
    void setX(int dx);
    void setY(int dy);
    void setD(direction d);
    direction getD() const;
    std::pair<int, int> getLocation();
    std::string  getInfo();
    virtual void move(direction dir) = 0;
};


#endif //SNAKEGAME_SEGMENT_H

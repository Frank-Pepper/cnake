#ifndef SNAKEGAME_HEAD_H
#define SNAKEGAME_HEAD_H

#include "Segment.h"

class Head : public Segment{
public:
    Head(int x_, int y_, direction direction_);
    void move(direction dir) override;
};


#endif //SNAKEGAME_HEAD_H

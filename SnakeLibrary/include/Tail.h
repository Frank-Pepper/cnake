#ifndef SNAKEGAME_TAIL_H
#define SNAKEGAME_TAIL_H

#include "Segment.h"

class Tail : public Segment{
public:
    Tail(int x_, int y_, direction direction_);
    void move(direction dir) override;
};


#endif //SNAKEGAME_TAIL_H

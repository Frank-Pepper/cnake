#include "Tail.h"

Tail::Tail(int x_, int y_, direction direction_) : Segment(x_, y_, direction_) {

}

void Tail::move(direction dir) {
    if( dir % 2 ){
        setY(dir - 2);
    }
    else{
        setX(dir - 3);
    }
    setD(dir);
}

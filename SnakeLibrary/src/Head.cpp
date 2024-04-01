#include "Head.h"
#include <cmath>

Head::Head(int x_, int y_, direction direction_) : Segment(x_, y_, direction_){
}

void Head::move(direction dir) {
    if( abs(dir-getD()) != 2 ){
        if( dir % 2 ){
            setY(dir - 2);
        }
        else{
            setX(dir - 3);
        }
        setD(dir);
    }
    else {
        dir = this->getD();
        if( dir % 2 ){
            setY(dir - 2);
        }
        else{
            setX(dir - 3);
        }
    }
}




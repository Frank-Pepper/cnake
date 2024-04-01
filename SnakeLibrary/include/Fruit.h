#ifndef SNAKEGAME_FRUIT_H
#define SNAKEGAME_FRUIT_H

#include <utility>

class Fruit {
private:
    int x = 0;
    int y = 0;
public:
    Fruit();
    std::pair<int, int> getLocation();
    void setX(int x);
    void setY(int y);

};


#endif //SNAKEGAME_FRUIT_H

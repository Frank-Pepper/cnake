#include "Fruit.h"

Fruit::Fruit(){}

std::pair<int, int> Fruit::getLocation()
{
    return std::pair<int, int>(x, y);
}

void Fruit::setX(int x)
{
    Fruit::x = x;
}

void Fruit::setY(int y)
{
    Fruit::y = y;
}



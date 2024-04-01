#include "Segment.h"

Segment::Segment(int x, int y, direction d) : x(x), y(y), D(d) {}

void Segment::setX(int dx) {
    Segment::x += dx;
}

void Segment::setY(int dy) {
    Segment::y += dy;
}

void Segment::setD(direction d) {
    D = d;
}

direction Segment::getD() const {
    return D;
}

std::pair<int, int> Segment::getLocation() {
    return std::pair<int, int>(x, y);
}

std::string Segment::getInfo() {
    return "(" + std::to_string(x) + " ; " + std::to_string(y) + "), ";
}
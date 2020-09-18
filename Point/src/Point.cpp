#include <stdexcept>

#include "Point.h"

namespace task2 {

Point::Point(int x, int y) : x_(x), y_(y) {}

void Point::shift(int shf) {
    // todo
    throw std::runtime_error("Not implemented!");
}

void Point::shift(int xSh, int ySh) {
    // todo
    throw std::runtime_error("Not implemented!");
}

void Point::shift(const Point& pt) {
    // todo
    throw std::runtime_error("Not implemented!");
}

int Point::getX() const {
    return x_;
}

int Point::getY() const {
    return y_;
}

void Point::setX(int x) {
    x_ = x;
}

void Point::setY(int y) {
    y_ = y;
}

}
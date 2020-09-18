#include <iostream>

// В основном используются как сущность для хранения переменных, но может использоваться как класс
// Отличие от класса - по умолчанию все public, у класса - private
struct Point {
    int x;
    int y;
};

int main() {
    Point p = {1, 2};
    std::cout << "x: " << p.x << ", y: " << p.y << std::endl;
    return 0;
}
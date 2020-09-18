// Проверка на подключение заголовочного файла в единственном экземпляре
#ifndef CPP_POINT_H
#define CPP_POINT_H

namespace task2 {

/** \brief Точка с двумя целочисленными координатами.
 *
 *  Координаты точки бесконечны, за значением INT32_MAX следует значение INT32_MIN.
 */
class Point {

public:
    /// Конструктор инициализирует объект точки двумя координатами.
    explicit Point(int x = 0, int y = 0);

public:
    /// Сдвигает координаты, добавляя заданное значение shf к обеим координатам.
    void shift(int shf);

    /// Сдвигает координаты, добавляя заданные значения соответствующих координат xSh и ySh.
    void shift(int xSh, int ySh);

    /// Сдвигает координаты, добавляя значения соответствующих координат заданной точки pt.
    void shift(const Point& pt);

public:

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);

protected:
    int x_;
    int y_;
};

}

#endif //CPP_POINT_H
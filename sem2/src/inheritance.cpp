#include <iostream>

// Абстрактный класс
class Figure {
public:
    explicit Figure(char sign) {
        this->sign = sign;
    }

    // virtual - функция, которая может быть переопределена в наследуемом классе
    virtual void showFigureSign() {
        std::cout << sign << std::endl;
    };

    // = 0 в конце - указать, что данная функция ДОЛЖНА быть определена в наследуемом классе
    virtual double getSquare() = 0;

    virtual double getPerimeter() = 0;

    // Для абстрактных классов всегда нужно иметь переопределяемый деструктор,
    // чтобы определить логику освобождения памяти в наследуемых классах!
    // Деструктор базового класса вызовится последним!
    // = default - сказать компилятору вручную определить функцию из большой пятерки или конструктора по умолчанию,
    // в данном случае у нас нет динамически выделенных переменных, поэтому он справится.
    virtual ~Figure() = default;

protected:
    char sign;
};

// public перед базовым классом Figure означает, что все наследуемые члены класса
// будут доступны с тем же модификатором доступа, что и у базового класса
// (если поставить, например, protected, то наследуемые члены класса с модификатором доступа
// public станут protected, а private так и останутся private)
class Rectangle : public Figure {
public:
    // Вызываем так же конструктор базового класса!
    Rectangle(double w, double h) : Figure('R'), width(w), height(h) {}

    ~Rectangle() override = default;

    // override указывает что функция переопределяет виртуальную функцию родителя
    // Функция все так же остается virtual!
    double getSquare() override {
        return width * height;
    }

    double getPerimeter() override {
        return width * 2 + height * 2;
    }

private:
    double width;
    double height;
};

class Circle : public Figure {
public:
    // constexpr расчитывает переменную на этапе компиляции
    // Для статичных констант класса она также необходима
    constexpr static double PI = 3.14;
public:
    explicit Circle(double r) : Figure('C'), radius(r) {}

    ~Circle() override = default;

    double getSquare() override {
        return radius * radius * 3.14;
    }

    double getPerimeter() override {
        return 2 * PI * radius;
    }

    // final - запрет переопределения этой функции в наследуемых классах
    void showFigureSign() final {
        std::cout << "Circle special sign: " << sign << std::endl;
    };

    // Статичная функция, для ее вызова не нужен экземпляр класса
    static void printPI() {
        std::cout << "PI = " << PI << std::endl;
    }

private:
    double radius;
};

int main() {
    using namespace std;

    Figure* rect = new Rectangle(20, 30);
    Figure* circle = new Circle(30);

    // -> разыменовывает указатель, такое же поведение как (*rect).getSquare()
    cout << "Rectangle square: " << rect->getSquare() << endl;
    cout << "Circle square: " << circle->getSquare() << endl;

    rect->showFigureSign();
    circle->showFigureSign();

    cout << "Static Circle field PI = " << Circle::PI << endl;
    Circle::printPI();

    delete rect;
    delete circle;

    return 0;
}
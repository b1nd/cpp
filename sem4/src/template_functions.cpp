#include <iostream>

class A {
public:
    explicit A(int value) {
        this->value = value;
    }

    friend A operator+(const A& left, const A& right) {
        return A(left.value + right.value);
    }

    friend std::ostream& operator<<(std::ostream& out, const A& a) {
        out << "A value: " << a.value;
        return out;
    }

private:
    int value;
};

template<typename T>
T sum(const T& a, const T& b) {
    return a + b;
}

template<class... Targs>
auto sumVararg(Targs&&... args) {
    // Применение оператора + для всех аргуметнов
    return (args + ...);
}

template<typename T, typename U>
T create(const U& value) {
    // Вызов конструктора
    return T(value);
}

int main() {
    using namespace std;

    int aInt = 1;
    int bInt = 2;
    double aDouble = 1.5;
    double bDouble = 3.7;
    const string aString = "a";
    const string bString = "b";
    const A a1 = A(1);
    const A a2 = A(2);

    cout << "sum(aInt, bInt): " << sum(aInt, bInt) << endl;
    cout << "sum(aDouble, bDouble): " << sum(aDouble, bDouble) << endl;
    cout << "sum<double>(aInt, bDouble): " << sum<double>(aInt, bDouble) << endl;
    cout << "sum(aString, bString): " << sum(aString, bString) << endl;
    cout << "sum(a1, a2): " << sum(a1, a2) << endl;

    int cInt = 3;
    A a3 = A(3);
    cout << "sumVararg(aInt, bInt, cInt): " << sumVararg(aInt, bInt, cInt) << endl;
    cout << "sumVararg(a1, a2, a3): " << sumVararg(a1, a2, a3) << endl;

    A a = create<A, int>(22);
    auto s = create<string, string>("some string");

    cout << "a: " << a << endl;
    cout << "s: " << s << endl;

    return 0;
}
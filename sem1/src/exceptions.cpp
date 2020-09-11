#include <iostream>

using namespace std;

void throwException() {
    throw std::runtime_error("Some exception!");
}

double divide(int a, int b) {
    if (b == 0) throw std::logic_error("Division by zero!");

    return static_cast<double>(a) / b;
}

// Кастомные исключения рекомендуется наследовать от std::exception!
int main() {
    int a;
    int b;
    cout << "Input dividend" << endl;
    cin >> a;
    cout << "Input divisor" << endl;
    cin >> b;

    try {
        double c = divide(a, b);
        cout << "division result = " << c << endl;

        throwException();
    } catch (std::logic_error& e) {
        cout << "This is logic error: " << e.what() << endl;
    } catch (std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
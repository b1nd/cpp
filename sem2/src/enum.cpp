#include <iostream>

enum Operations {
    // По умолчанию начинается с нуля, но можно задать начальное значение
    add = 1,
    // Далее элементы инкриментируются
    subtract, //2
    // Можно переопределить
    multiply = 4
};

int main() {
    using namespace std;

    int operation;
    int x1;
    int x2;
    int result;

    cout << "Add: 1 \tSubtract: 2 \tMultiply: 4" << endl;
    cout << "Input x1: " << endl;
    cin >> x1;
    cout << "Input x2: " << endl;
    cin >> x2;
    cout << "Input operation number: " << endl;
    cin >> operation;

    switch (operation) {
        case Operations::add:
            result = x1 + x2;
            break;
        case Operations::subtract:
            result = x1 - x2;
            break;
        case Operations::multiply:
            result = x1 * x2;
            break;
        default:
            cout << "Unknown operation" << endl;
            return 0;
    }
    cout << "Result: " << result << endl;

    return 0;
}
#include <iostream>

enum class Operations : int {
    // По умолчанию начинается с нуля, но можно задать начальное значение
    Add = 1,
    // Далее элементы инкриментируются
    Subtract, //2
    // Можно переопределить
    Multiply = 4
};

int main() {
    using namespace std;

    int x1;
    int x2;
    int result;
    int operationInt;

    cout << "Add: " << static_cast<int>(Operations::Add) << "\t";
    cout << "Subtract: " << static_cast<int>(Operations::Subtract) << "\t";
    cout << "Multiply: " << static_cast<int>(Operations::Multiply) << endl;

    cout << "Input x1: " << endl;
    cin >> x1;
    cout << "Input x2: " << endl;
    cin >> x2;
    cout << "Input operation number: " << endl;
    cin >> operationInt;

    auto operationEnum = static_cast<Operations>(operationInt);

    switch (operationEnum) {
        case Operations::Add:
            result = x1 + x2;
            break;
        case Operations::Subtract:
            result = x1 - x2;
            break;
        case Operations::Multiply:
            result = x1 * x2;
            break;
        default:
            cout << "Unknown operation" << endl;
            return 0;
    }
    cout << "Result: " << result << endl;

    return 0;
}
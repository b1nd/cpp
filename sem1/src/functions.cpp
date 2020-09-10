#include <iostream>

using namespace std;

// inline означает, что код функции подставится на месте каждого ее вызова при компиляции
inline void printHello() {
    cout << "Hello";
}

void printHelloWorld() {
    // Функцию в файле можно использовать только если она объявлена выше
    printHello();
    cout << " world!" << endl;
}

// Сигнатура функции без реализации, реализация в конце файла
int increment(int);

// Параметры передаются по ссылке
void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

// Запрет на изменение аргумента функции
int square(const int& a) {
    // a = a * a; // не скомпилируется
    return a * a;
}

int returnFirst(int a, int b) {
    return a;
}

int returnSecond(int a, int b) {
    return b;
}

// В качестве параметров можно передавать функции по их сигнатуре
int returnFunction(int a, int b, int (* passedFunction)(int, int)) {
    return passedFunction(a, b);
}

// Функция с параметром b по умолчанию
int sum(int a, int b = 0) {
    return a + b;
}

// Перегрузка функции
double sum(double a, double b) {
    return a + b;
}

int main() {
    printHelloWorld();

    cout << "increment(1): " << increment(1) << endl;

    int a = 1;
    int b = 2;

    swap(a, b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "returnFunction(1, 2, returnFirst): " << returnFunction(1, 2, returnFirst) << endl;
    cout << "returnFunction(1, 2, returnSecond): " << returnFunction(1, 2, returnSecond) << endl;

    cout << "sum(5): " << sum(5) << endl;
    cout << "sum(5, 1): " << sum(5, 1) << endl;
    cout << "sum(0.1, 0.4): " << sum(0.1, 0.4) << endl;

    return 0;
}

int increment(int x) {
    return x + 1;
}
#include <iostream>

using namespace std;

int main() {
    int a = 2u << 2u; // 10 на два разряда влево = 1000 = 8 в десятичной
    int b = 16u >> 3u; // 10000 на три разряда вправо = 10 = 2 в десятичной

    int c = 5u | 2u; // 101 | 010 = 111 = 7 в десятичной
    int d = 6u & 2u; // 110 & 010 = 10 = 2 в десятичной
    int e = 5u ^ 1u; // 101 ^ 001 = 100 = 4 в десятичной
    int f = ~9u; // -10

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;
    // Побитовые операции можно также использовать сразу с оператором присваивания
    f ^= f;
    cout << "f ^= f: " << f << endl;

    return 0;
}
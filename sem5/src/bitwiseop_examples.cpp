#include <iostream>

using namespace std;

// Количество ведущих нулей
unsigned int leadingZeroesNumber(unsigned int x) {
    if (!x) return 32;
    unsigned int n = 1;
    if ((x >> 16u) == 0) {n = n + 16; x = x << 16u;}
    if ((x >> 24u) == 0) {n = n + 8; x = x << 8u;}
    if ((x >> 28u) == 0) {n = n + 4; x = x << 4u;}
    if ((x >> 30u) == 0) {n = n + 2; x = x << 2u;}
    n = n - (x >> 31u);
    return n;
}

// Установить значение определенного бита (value - true, если необходимо установить 1)
void setBit(unsigned int& src, unsigned int index, bool value) {
    if (value) {
        src |= (1u << index);
    } else {
        src &= ~(1u << index);
    }
}

// Получить значение определенного бита
bool getBit(unsigned int src, unsigned int index) {
    return src &= (1u << index);
}

int main() {
    cout << leadingZeroesNumber(1u << 15u) << endl;
    unsigned int x = 7;
    cout << "x bit at index 1: " << getBit(x, 1) << endl;
    setBit(x, 1, false);
    cout << "x bit at index 1 after setBit(x, 1, false): " << getBit(x, 1) << endl;
    cout << "x after setBit(x, 1, false): " << x << endl;

    return 0;
}
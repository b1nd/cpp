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

// Подсчет количества единичных битов
unsigned int popcnt(unsigned int x) {
    x = x - ((x >> 1u) & 0x55555555u);
    x = (x & 0x33333333u) + ((x >> 2u) & 0x33333333u);
    x = (x + (x >> 4u)) & 0x0F0F0F0Fu;
    x = x + (x >> 8u);
    x = x + (x >> 16u);
    return x & 0x0000003Fu;
}

int main() {
    cout << leadingZeroesNumber(1u << 15u) << endl;
    unsigned int x = 7;
    cout << "x bit at index 1: " << getBit(x, 1) << endl;
    setBit(x, 1, false);
    cout << "x bit at index 1 after setBit(x, 1, false): " << getBit(x, 1) << endl;
    cout << "x after setBit(x, 1, false): " << x << endl;

    cout << "popcnt(7): " << popcnt(7) << endl; // 111
    cout << "popcnt(5): " << popcnt(5) << endl; // 101

    return 0;
}
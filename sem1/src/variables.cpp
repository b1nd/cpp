#include <iostream>

using namespace std;

void printCallsNumber() {
    static int i = 0;
    ++i;
    cout << "Call #" << i << endl;
}

// В зависимости от ОС и архитектуры процессора размер типа может меняться!
int main() {
    // Здесь будет случайное значение, не 0!
    int uninitialized;
    int initialized = 1;

    cout << "uninitialized: " << uninitialized << endl;
    cout << "initialized: " << initialized << endl;

    // static инициализирует переменную дефолтным значением
    static int zero;
    cout << "zero: " << zero << endl;

    // Инициализированная static-переменная остается в памяти до конца программы!
    // Поэтому ее лучше использовать вместе с const для объявления констант
    // Если объявить в одном файле (не классе), она будет недоступна вне этого файла
    printCallsNumber();
    printCallsNumber();

    bool booleanTrue = true;
    bool booleanFalse = false;

    cout << "booleanTrue: " << booleanTrue << endl;
    cout << "booleanFalse: " << booleanFalse << endl;

    // ASCII
    char charA = 'a';
    char charCodeA = 97;

    cout << "charA: " << charA << endl;
    cout << "charCodeA: " << charCodeA << endl;

    // Unicode
    wchar_t wideChar = '\u0041';
    // Через cout выведет числовой код
    wcout << "wideChar: " << wideChar << endl;

    // Целочисленые (по умолчанию являются signed)
    // 2 байта
    short signedShort = -1;
    unsigned short unsignedShort = 1;
    // 4 или 2 байта
    int signedInt = INT16_MIN;
    unsigned int unsignedInt = 0x1FC;
    // 4 байта
    long signedLong = 2147483647;
    unsigned long unsignedLong = UINT32_MAX;
    // 8 байт
    long long signedLongLong = 9223372036854775807;
    unsigned long long unsignedLongLong = signedLongLong * 2;

    // sizeof() - размер в байтах
    cout << "sizeof(char): " << sizeof(char) << endl;
    cout << "sizeof(short): " << sizeof(short) << endl;
    cout << "sizeof(unsigned short): " << sizeof(unsigned short) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(unsigned int): " << sizeof(unsigned int) << endl;
    cout << "sizeof(long): " << sizeof(long) << endl;
    cout << "sizeof(unsigned long): " << sizeof(unsigned long) << endl;
    cout << "sizeof(long long): " << sizeof(long long) << endl;
    cout << "sizeof(unsigned long long): " << sizeof(unsigned long long) << endl;

    // Вещественные
    // 4 байта
    float eFloat = 2e-6;
    // 8 байт
    double doubleFloat = 0.00001;
    // 8 байт
    long double longDouble = 0.00000000000000001;

    cout << "eFloat: " << eFloat << endl;
    cout << "doubleFloat: " << doubleFloat << endl;

    // Автоопределение типа
    auto a = 1;
    const auto b = a;
    // b = 2 // нельзя
    cout << "b: " << b << endl;

    double c = 2.7;
    // Приведение double к int
    auto d = static_cast<int>(c);
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    return 0;
}
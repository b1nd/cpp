#include <iostream>

using namespace std;

int main() {
    int number = 5;
    int& refNumber = number;
    cout << refNumber << endl; // 5
    refNumber = 20;
    cout << number << endl; // 20

    int x = 10;
    // & - получить адрес памяти, в котором хранится значение x
    // type* означает, что переменная является указателем (занимает int32 байт, вне зависимости от типа)
    int* ptr = &x;
    cout << "Address = " << ptr << endl;
    // * перед переменной типа указатель - разименовывание указателя,
    // чтобы получить значение, находящееся по адресу памяти, на которое указывает указатель
    cout << "Value = " << *ptr << endl;

    int a = 10;
    int b = 6;

    // Нулевой указатель
    int* p = nullptr;
    // Ссылка на указатель
    int*& pRef = p;
    // Через ссылку указателю p присваивается адрес переменной a
    pRef = &a;
    cout << "p value = " << *p << endl; // 10
    // Изменяем значение по адресу, на который указывает указатель
    *pRef = 70;
    cout << "a value = " << a << endl; // 70

    // Изменяем адрес, на который указывает указатель
    pRef = &b;
    cout << "p value = " << *p << endl; // 6

    int c = 1;
    int* cPtr = &c;
    cout << "cPtr address = " << cPtr << endl;
    // Указатель + i = адрес указателя + размер типа объекта, на который указывает * i
    cout << "cPtr + 1 address = " << cPtr + 1 << endl;

    int d = 5;
    // Указатель на константу
    const int* pd = &d;
    cout << "pd value = " << *pd << endl; // 5
    d = 10;
    cout << "pd value = " << *pd << endl; // 10
    pd = &c;
    cout << "pd value = " << *pd << endl; // 1
    // *pd = 34; // Ошибка компиляции

    int e = 15;
    // Константный указатель
    int* const pe = &e;
    cout << "pe value = " << *pe << endl; // 15
    *pe = 20;
    cout << "pe value = " << *pe << endl; // 20
    // pa = &c; // Ошибка компиляции

    int f = 10;
    // Константный указатель на константу (ограничения обеих const)
    const int* const pf = &f;

    return 0;
}
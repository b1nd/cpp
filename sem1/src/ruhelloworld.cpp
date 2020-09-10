#include <iostream>

using namespace std;

int main() {
    // Подключить русскую локаль, в зависимости от макроса константы LC_ALL меняется поведение
    // от отображения кириллицы, до работы функций со временем и парсингом строк
    // Для исходного файла с кодировкой windows-1251
    // setlocale(LC_ALL, "Russian");
    // Для исходного файла с кодировкой UTF-8
    setlocale(LC_ALL, "ru_RU.UTF-8");

    cout << "Привет, мир!" << endl;

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    // Статический массив удалять руками не нужно!
    int staticArray[3] = {1, 2, 3};
    for (int i = 0; i < 3; ++i) {
        cout << "staticArray[" << i << "]: address=" << staticArray + i
             << "\tvalue=" << *(staticArray + i) << endl;
    }

    int dynamicArrayLength = 10;
    int* dynamicArray = new int[dynamicArrayLength];
    for (int i = 0; i < dynamicArrayLength; ++i) {
        dynamicArray[i] = i;
    }
    cout << "dynamicArray[2] = " << dynamicArray[2] << endl;
    // Выход за пределы массива НИКАК не контролируется!
    // Значение из следующей ячейки может считаться, а может быть и ошибка доступа к этому региону памяти
    // cout << dynamicArray[10] << endl;

    // Обязательно освобождаем память!
    delete[] dynamicArray;

    int rows = 3;
    int cols = 7;
    // Двумерный массив
    int** arr = new int* [rows];
    // Инициализация массивов
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = cols * i + j;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    // Удаление двумерного массива
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}
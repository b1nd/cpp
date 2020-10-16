#include <iostream>
#include <vector>

using namespace std;

// https://docs.microsoft.com/ru-ru/cpp/standard-library/vector-class
// vector<bool> - работает как bitset
int main() {
    vector<int> vect{2, 4, 1, 5, 7, 3, 6};
    vect.push_back(9);
    vect.push_back(8);

    cout << "vector: " << "\n";
    for (auto& el : vect) {
        cout << el << " ";
    }
    cout << endl;

    cout << "reverse vector: " << "\n";
    for (auto&& it = vect.rbegin(); it != vect.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Глубокая копия через конструктор копирования
    auto vectCopy = vect;
    // Доступ к элементу по индексу
    vectCopy[0] = 1;

    auto fourthElementIt = vectCopy.begin() + 3;
    // Добавляет элемент в указанную позицию, сдвигая элемент по этой позиции и элементы правее него вправо
    vectCopy.insert(fourthElementIt, 10);

    // Удаляет элемент и сдвигает элементы правее него влево
    vectCopy.erase(vectCopy.end() - 2);

    cout << "new vector: " << "\n";
    for (auto& el : vectCopy) cout << el << " ";
    cout << endl;

    // Конструктор заполнения конкретным значением
    vector ones(5, 1);
    cout << "ones: " << "\n";
    for (auto& el : ones) cout << el << " ";

    return 0;
}
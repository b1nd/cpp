#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l{2, 3, 4, 5, 6, 7, 8};
    l.push_back(9);
    l.push_front(1);

    cout << "list: ";
    for (auto&& it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
    cout << endl;

    l.pop_back();
    l.pop_front();
    cout << "l.front() after pop_front(): " << l.front() << endl;
    cout << "l.back() after pop_back(): " << l.back() << endl;

    auto&& it = l.begin();
    // Сдвиг итератора на 2 элемента
    advance(it, 2);
    // Если имеем заранее определенный итератор элемента, то вставка со сдвигом элемента будет за O(1)
    l.insert(it, 10);
    // Удаление по итератору
    l.erase(--l.end());

    cout << "final list: ";
    for (auto&& el : l) cout << el << " ";

    return 0;
}
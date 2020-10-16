#include <iostream>
#include <queue>

using namespace std;

// адаптеры не поддерживают итераторы -> и алгоритмы из std недоступны
int main() {
    priority_queue<int> q;
    int arr[] = {5, 2, 8, 4, 1, 9, 3};
    for (auto&& el : arr) {
        q.push(el);
    }
    cout << "q.top(): " << q.top() << endl; // top возвращает максимальный элемент
    q.pop();
    cout << "q.top() after q.pop(): " << q.top();
}
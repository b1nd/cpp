#include <iostream>
#include <queue>

using namespace std;

// адаптеры не поддерживают итераторы -> и алгоритмы из std недоступны
int main() {
    queue<int> q{{1, 2, 3}};
    q.push(4);
    cout << "q.front(): " << q.front() << endl;
    q.pop();
    cout << "q.size() after pop: " << q.size() << endl;
    cout << "q.front() after pop: " << q.front() << endl;
}
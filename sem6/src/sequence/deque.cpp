#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);
    d[0] = 9;

    cout << "deque: ";
    for (auto&& it = d.begin(); it != d.end(); it++)
        cout << *it << " ";
    cout << endl;

    d.pop_back();
    d.pop_front();

    cout << "d.front() after pop_front(): " << d.front() << endl;
    cout << "d.back() after pop_back(): " << d.back() << endl;

    d.insert(d.begin() + 1, 10);
    d.erase(d.begin() + 2);

    cout << "deque after insert(d.begin() + 1, 10) and erase(d.begin() + 2): ";
    for (auto&& el : d) cout << el << " ";

    return 0;
}
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> flist{1, 2, 3, 4, 5};
    flist.push_front(6);
    flist.insert_after(flist.begin(), 7);

    cout << "forward_list: ";
    for (auto&& el : flist) cout << el << " ";
    cout << endl;

    flist.pop_front();
    flist.erase_after(++flist.begin());

    cout << "forward_list after pop_front() and erase_after(++flist.begin()): ";
    for (auto&& el : flist) cout << el << " ";

    return 0;
}
#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 5> arr{1, 2, 3};
    arr[4] = 10;

    cout << "arr: ";
    for (auto&& el : arr) cout << el << " ";
    cout << endl;

    cout << "arr.front(): " << arr.front() << endl;
    cout << "arr.back(): " << arr.back() << endl;

    int* cArr = arr.data();

    cout << "arr.data(): ";
    for (size_t i = 0; i < arr.size(); i++) cout << cArr[i] << " ";
    cout << endl;

    cArr[0] = -1;
    cout << "arr after arr.data()[0] = -1: ";
    // cbegin() - константный итератор
    for (auto&& it = arr.cbegin(); it != arr.cend(); it++) {
        cout << *it << " ";
    }

    return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> mset {1, 1, 1, 2};
    for (auto& el : mset) {
        cout << el << "  ";
    }
    return 0;
}
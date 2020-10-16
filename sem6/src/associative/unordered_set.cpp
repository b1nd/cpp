#include <iostream>
#include <unordered_set>

using namespace std;

// hash set
int main() {
    unordered_set<int> s{2, 4, 1, 6, 1, 2};
    // итератор точно такой же как в set
    auto fourIt = s.insert(5);
    s.insert(3);
    s.insert(4);

    cout << "unordered set: " << "\n";
    for (auto& el : s) cout << el << " ";
    cout << endl;

    bool isFivePresent = s.find(5) != s.end();
    cout << boolalpha << "isFivePresent: " << isFivePresent << endl;

    auto c1 = s.erase(1);
    auto c2 = s.erase(10);
    cout << "s.erase(1): " << c1 << endl;
    cout << "s.erase(10): " << c2 << endl;

    cout << "unordered set after erase 1, 10: " << "\n";
    for (auto& el : s) cout << el << " ";
    cout << endl;

    return 0;
}
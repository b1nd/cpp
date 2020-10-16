#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_multiset<int> unorderedMultiset{2, 4, 1, 6, 1, 2};
    // итератор точно такой же как в set
    auto fourIt = unorderedMultiset.insert(5);
    unorderedMultiset.insert(1);

    cout << "unordered_multiset: ";
    for (auto& el : unorderedMultiset) cout << el << " ";
    cout << endl;

    // range(it1, it2) одинаковых элементов
    auto range = unorderedMultiset.equal_range(1);
    cout << "unorderedMultiset.equal_range(1): ";
    for (auto&& it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // количество элементов 1
    auto oneCount = unorderedMultiset.count(1);
    cout << "unorderedMultiset.count(1): " << oneCount << endl;

    cout << "unorderedMultiset.erase(1): " << unorderedMultiset.erase(1) << endl;

    cout << "unorderedMultiset after erase: ";
    for (auto& el : unorderedMultiset) cout << el << " ";
    cout << endl;

    return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> mset{2, 4, 1, 6, 1, 2};
    auto fourIt = mset.insert(5);
    mset.insert(1);

    cout << "multiset: " << "\n";
    for (auto& el : mset) cout << el << " ";
    cout << endl;

    // range(it1, it2) одинаковых элементов
    auto range = mset.equal_range(1);
    cout << "mset.equal_range(1): ";
    for (auto&& it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // количество элементов 1
    auto oneCount = mset.count(1);
    cout << "mset.count(1): " << oneCount << endl;

    multiset<int, std::greater<>> msetGreater{2, 4, 1, 6, 1, 1, 5, 2};
    cout << "msetGreater.size(): " << msetGreater.size() << endl;

    cout << "msetGreater: ";
    for (auto& el : msetGreater) cout << el << " ";
    cout << endl;

    cout << "msetGreater.erase(2): " << msetGreater.erase(2) << endl;

    cout << "msetGreater after erase: ";
    for (auto& el : msetGreater) cout << el << " ";
    cout << endl;

    return 0;
}
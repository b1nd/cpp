#include <iostream>
#include <set>

using namespace std;

// set на красно-черном дереве
int main() {
    set<int> s{2, 4, 1, 6, 1, 2};
    auto threeIt = s.insert(3);
    auto fourIt = s.insert(4);

    cout << boolalpha;
    cout << "*threeIt: " << *threeIt.first << endl;
    cout << "threeIt.second: " << threeIt.second << endl;
    cout << "*fourIt: " << *fourIt.first << endl;
    cout << "fourIt.second: " << fourIt.second << endl;

    cout << "set: " << "\n";
    for (auto& el : s) cout << el << " ";
    cout << endl;

    auto fourElementIt = s.find(4);
    cout << "fourElementIt: " << *fourElementIt << endl;
    auto fiveElementIt = ++fourElementIt;
    cout << "fiveElementIt: " << *fiveElementIt << endl;

    s.erase(fiveElementIt);
    // cout << "fiveElementIt: " << *fiveElementIt << endl; // runtime error
    bool isSixPresent = s.find(6) != s.end();
    cout << "isSixPresent after erase: " << isSixPresent << endl;

    // Указать порядок сортировки
    set<int, std::greater<>> greaterSet{2, 4, 1, 3, 6, 1, 2};
    cout << "greaterSet: " << "\n";
    for (auto& el : greaterSet) cout << el << " ";
    cout << endl;

    auto oneCount = greaterSet.count(1);
    cout << "greaterSet oneCount: " << oneCount << endl;

    return 0;
}
#include <iostream>
#include <map>

using namespace std;

int main() {
    multimap<int, string> mMap{
            {2, "b"},
            {1, "a"},
            {4, "d"},
            {2, "n"}
    };

    mMap.insert({4, "f"});
    auto threeIt = mMap.insert(pair(3, "c"));

    cout << "*threeIt: " << threeIt->first << "->" << threeIt->second << endl;

    cout << "multimap: ";
    for (auto&& p : mMap) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;

    // range(it1, it2) одинаковых элементов
    auto range = mMap.equal_range(2);
    cout << "mMap.equal_range(2): ";
    for (auto&& it = range.first; it != range.second; ++it) {
        cout << it->first << "->" << it->second << " ";
    }
    cout << endl;

    auto twoIt = mMap.find(2);
    if (twoIt != mMap.end()) {
        cout << "mMap.find(2)->second: " << twoIt->second << endl;
    }
    // insert value h by key 6
    mMap.insert({6, "h"});

    mMap.erase(4);

    cout << "final multimap: ";
    for (auto&& p : mMap) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;

    multimap<int, string, std::greater<>> mMapGreater{
            {2, "b"},
            {4, "d"},
            {1, "a"},
            {2, "l"},
            {4, "f"},
            {2, "b"},
            {3, "c"}
    };

    cout << "greater multimap: ";
    for (auto&& p : mMapGreater) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;

    cout << "mMapGreater.count(2): " << mMapGreater.count(2) << endl;
    cout << "mMapGreater.erase(2): " << mMapGreater.erase(2) << endl;

    cout << "greater multimap after erase(2): ";
    for (auto&& p : mMapGreater) {
        cout << p.first << "->" << p.second << " ";
    }

    return 0;
}
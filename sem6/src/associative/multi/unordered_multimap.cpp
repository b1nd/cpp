#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_multimap<int, string> unorderedMultimap{
            {2, "b"},
            {4, "d"},
            {1, "a"},
            {2, "l"},
            {4, "f"},
            {2, "b"},
            {3, "c"}
    };

    unorderedMultimap.insert({4, "k"});
    auto threeIt = unorderedMultimap.insert(pair(3, "p"));

    cout << "*threeIt: " << threeIt->first << "->" << threeIt->second << endl;

    cout << "unorderedMultimap: ";
    for (auto&& p : unorderedMultimap) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;

    // range(it1, it2) одинаковых элементов
    auto range = unorderedMultimap.equal_range(4);
    cout << "unorderedMultimap.equal_range(4): ";
    for (auto&& it = range.first; it != range.second; ++it) {
        cout << it->first << "->" << it->second << " ";
    }
    cout << endl;

    auto twoIt = unorderedMultimap.find(2);
    if (twoIt != unorderedMultimap.end()) {
        cout << "unorderedMultimap.find(2)->second: " << twoIt->second << endl;
    }
    // insert value h by key 6
    unorderedMultimap.insert({6, "h"});

    unorderedMultimap.erase(3);

    cout << "mMapGreater.count(4): " << unorderedMultimap.count(4) << endl;
    cout << "mMapGreater.erase(4): " << unorderedMultimap.erase(4) << endl;

    cout << "final unorderedMultimap: ";
    for (auto&& p : unorderedMultimap) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;

    return 0;
}
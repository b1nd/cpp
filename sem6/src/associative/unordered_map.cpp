#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> unorderedMap{
            {2, "b"},
            {1, "a"},
            {4, "d"}
    };

    // такой же как у map
    auto threeIt = unorderedMap.insert(pair(3, "c"));
    unorderedMap.insert({4, "f"});

    cout << "unordered_map: ";
    for (auto&& p : unorderedMap) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;

    // set value g for key 2
    unorderedMap[2] = "g";

    cout << "m[1]: " << unorderedMap[1] << endl;

    // insert value h by key 6
    unorderedMap[6] = "h";

    unorderedMap.erase(4);

    cout << "final unordered_map: ";
    for (auto&& p : unorderedMap) {
        cout << p.first << "->" << p.second << " ";
    }

    return 0;
}
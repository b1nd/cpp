#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> m{
            {2, "b"},
            {1, "a"},
            {4, "d"}
    };

    auto threeIt = m.insert(pair(3, "c"));
    auto fourIt = m.insert({4, "f"});

    cout << boolalpha;
    cout << "*threeIt: " << threeIt.first->first << "->" << threeIt.first->second << endl;
    cout << "threeIt.second: " << threeIt.second << endl;
    cout << "*fourIt: " << fourIt.first->first << "->" << fourIt.first->second << endl;
    cout << "fourIt.second: " << fourIt.second << endl;

    cout << "map: ";
    for (auto&& p : m) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;

    // set value g for key 2
    m[2] = "g";

    cout << "m[1]: " << m[1] << endl;
    cout << "m[10]: " << m[10] << endl;

    // insert value h by key 6
    m[6] = "h";

    m.erase(4);

    cout << "final map: ";
    for (auto&& p : m) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;

    map<int, string, std::greater<>> mGreater{
            {2, "b"},
            {4, "d"},
            {1, "a"},
            {4, "f"},
            {3, "c"}
    };

    cout << "final greater map: ";
    for (auto&& p : mGreater) {
        cout << p.first << "->" << p.second << " ";
    }

    return 0;
}
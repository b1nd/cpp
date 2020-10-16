#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template<class InIt, class OutIt>
void printCollection(InIt beginIt, OutIt endIt) {
    std::for_each(beginIt, endIt, [](auto&& n) { cout << " " << n; });
}

int main() {
    vector arr{2, 5, 4, 3, 1, 9, 7, 8};

    cout << "arr:";
    printCollection(arr.begin(), arr.end());
    cout << endl;

    // mix max
    auto&& min = std::min_element(arr.begin(), arr.end());
    auto&& max = std::max_element(arr.begin(), arr.end());

    cout << "min: " << *min << endl;
    cout << "max: " << *max << endl;

    // vector with transformed elements
    vector<int> arrPlus5;
    // map elements
    std::transform(arr.begin(), arr.end(), std::back_inserter(arrPlus5), [](auto&& n) { return n + 5; });
    cout << "arr + 5:";
    printCollection(arrPlus5.begin(), arrPlus5.end());
    cout << endl;

    vector<int> sortedArr = arr;
    // sort
    std::sort(sortedArr.begin(), sortedArr.end());
    cout << "sortedArr:";
    printCollection(sortedArr.begin(), sortedArr.end());
    cout << endl;

    // binary search on sorted vector
    bool isEightPresent = std::binary_search(sortedArr.begin(), sortedArr.end(), 8);
    cout << boolalpha << "isEightPresent: " << isEightPresent << endl;

    // filter
    vector<int> evenArr;
    auto isEven = [](auto&& n) { return n % 2 == 0; };
    std::remove_copy_if(arr.begin(), arr.end(), std::back_inserter(evenArr), isEven);
    cout << "even arr:";
    printCollection(evenArr.begin(), evenArr.end());
    cout << endl;

    // set intersection
    set<int> set1{1, 2, 3, 4};
    set<int> set2{3, 4, 5, 6};
    cout << "set1:";
    printCollection(set1.begin(), set1.end());
    cout << endl;
    cout << "set2:";
    printCollection(set2.begin(), set2.end());
    cout << endl;

    set<int> intersectionSet;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          std::inserter(intersectionSet, intersectionSet.begin()));
    cout << "intersectionSet:";
    printCollection(intersectionSet.begin(), intersectionSet.end());

    return 0;
}
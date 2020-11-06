#include <gtest/gtest.h>
#include <stdexcept>
#include "vector"

using namespace std;

/**
 * По массиву arr длинной N с шагом 1 движется "окно" длины K, для каждого положения окна необходимо
 * вывести минимум из тех элементов, на которые окно указывает.
 */
vector<int> minWindow(const vector<int>& arr, int k);

#pragma region minWindow tests

TEST(minWindow, case1) {
    vector<int> arr{1, 3, 2, 4, 5, 3, 1};

    vector<int> expected{1, 2, 2, 3, 1};
    vector<int> result = minWindow(arr, 3);

    EXPECT_EQ(expected, result);
}

#pragma endregion

TEST(minWindow, case2) {
    vector<int> arr{1, 3, 2, 4, 5, 3, 1};

    vector<int> expected{1};
    vector<int> result = minWindow(arr, 7);

    EXPECT_EQ(expected, result);
}

TEST(minWindow, case3) {
    vector<int> arr{4, 3, 3, 8, 4, 2, 9, 0, 3, 4, 5, 9, 3, 1, 0};

    vector<int> expected{3, 2, 2, 0, 0, 0, 0, 0, 3, 1, 0};
    vector<int> result = minWindow(arr, 5);

    EXPECT_EQ(expected, result);
}

#pragma endregion

vector<int> minWindow(const vector<int>& arr, int k) {
    throw std::runtime_error("Not implemented!");
}
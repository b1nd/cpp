#include <gtest/gtest.h>
#include <stdexcept>
#include "vector"

using namespace std;

/**
 * Получает уникальные элементы массива arr.
 * Порядок элементов должен быть сохранен!
 */
vector<int> unique(const vector<int>& arr);

#pragma region unique tests

TEST(unique, case1) {
    vector<int> arr{1, 7, 2, 2, 4, 3, 5, 3, 7, 7};
    vector<int> expected{1, 7, 2, 4, 3, 5};
    EXPECT_EQ(expected, unique(arr));
}

TEST(unique, case2) {
    vector<int> arr{1, 1, 1};
    vector<int> expected{1};
    EXPECT_EQ(expected, unique(arr));
}

TEST(unique, case3) {
    vector<int> arr;
    EXPECT_TRUE(unique(arr).empty());
}

#pragma endregion

vector<int> unique(const vector<int>& arr) {
    throw std::runtime_error("Not implemented!");
}
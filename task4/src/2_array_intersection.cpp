#include <gtest/gtest.h>
#include <stdexcept>
#include "vector"
#include "algorithm"

using namespace std;

/**
 * Получает элементы, которые есть в обоих массивах first и second.
 * Порядок элементов не важен.
 */
vector<int> intersection(const vector<int>& first, const vector<int>& second);

#pragma region intersection tests

TEST(intersection, case1) {
    vector<int> first{4, 2, 1, 3, 5, 7, 6};
    vector<int> second{3, 9, 2, 11, 4, 8};

    vector<int> expected{2, 3, 4};
    vector<int> result = intersection(first, second);
    std::sort(expected.begin(), expected.end());
    std::sort(result.begin(), result.end());

    EXPECT_EQ(expected, result);
}

TEST(intersection, case2) {
    vector<int> first{1, 3, 2};
    vector<int> second{5, 6, 4};
    EXPECT_TRUE(intersection(first, second).empty());
}

TEST(intersection, case3) {
    vector<int> first;
    vector<int> second;
    EXPECT_TRUE(intersection(first, second).empty());
}

#pragma endregion

vector<int> intersection(const vector<int>& first, const vector<int>& second) {
    throw std::runtime_error("Not implemented!");
}
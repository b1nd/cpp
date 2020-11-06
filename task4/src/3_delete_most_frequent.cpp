#include <gtest/gtest.h>
#include <stdexcept>
#include "vector"
#include "algorithm"

using namespace std;

/**
 * Удаляет наиболее часто встречающийся элемент в массиве arr.
 * Если таких элементов несколько, удаляет все.
 * Порядок элементов должен быть сохранен!
 */
vector<int> deleteMostFrequent(const vector<int>& arr);

#pragma region deleteMostFrequent tests

TEST(deleteMostFrequent, case1) {
    vector<int> arr{4, 5, 2, 5, 3, 3, 6, 5};

    vector<int> expected{4, 2, 3, 3, 6};
    vector<int> result = deleteMostFrequent(arr);

    EXPECT_EQ(expected, result);
}

TEST(deleteMostFrequent, case2) {
    vector<int> arr{4, 5, 3, 2, 5, 3, 3, 6, 5};

    vector<int> expected{4, 2, 6};
    vector<int> result = deleteMostFrequent(arr);

    EXPECT_EQ(expected, result);
}

TEST(deleteMostFrequent, case3) {
    vector<int> arr{1, 2, 3};
    vector<int> result = deleteMostFrequent(arr);

    EXPECT_TRUE(result.empty());
}

#pragma endregion

vector<int> deleteMostFrequent(const vector<int>& arr) {
    throw std::runtime_error("Not implemented!");
}
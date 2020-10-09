#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

// Удалить i-й бит. Все старшие биты сдвигаются вправо
unsigned int deleteBit(unsigned int n, unsigned int index);

#pragma region deleteBit tests

TEST(deleteBit, case1) {
    EXPECT_EQ(3, deleteBit(7, 1));
}

TEST(deleteBit, case2) {
    EXPECT_EQ(0, deleteBit(4, 2));
}

TEST(deleteBit, case3) {
    EXPECT_EQ(INT32_MAX, deleteBit(-1, 31));
}

#pragma endregion

// todo
unsigned int deleteBit(unsigned int n, unsigned int index) {
    throw std::runtime_error("Not implemented!");
}
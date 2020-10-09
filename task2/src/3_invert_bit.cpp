#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

// Инвертировать i-й бит числа
unsigned int invertBit(unsigned int n, unsigned int i);

#pragma region invertBit tests

TEST(invertBit, case1) {
    EXPECT_EQ(1, invertBit(0, 0));
}

TEST(invertBit, case2) {
    EXPECT_EQ(3, invertBit(7, 2));
}

TEST(invertBit, case3) {
    EXPECT_EQ(15, invertBit(7, 3));
}

TEST(invertBit, case4) {
    EXPECT_EQ(INT32_MIN, invertBit(0, 31));
}

TEST(invertBit, case5) {
    EXPECT_EQ(2147483641, invertBit(-7, 31));
}

#pragma endregion

// todo
unsigned int invertBit(unsigned int n, unsigned int i) {
    throw std::runtime_error("Not implemented!");
}
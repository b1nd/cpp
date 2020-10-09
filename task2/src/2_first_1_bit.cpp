#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

// Найти позицию первого единичного бита слева
int first1Bit(unsigned int n);

#pragma region first1Bit tests

TEST(first1Bit, case1) {
    EXPECT_EQ(3, first1Bit(13));
}

TEST(first1Bit, case2) {
    EXPECT_EQ(5, first1Bit(32));
}

TEST(first1Bit, case3) {
    EXPECT_ANY_THROW(first1Bit(0));
}

TEST(first1Bit, case4) {
    EXPECT_EQ(31, first1Bit(-1));
}

#pragma endregion

// todo
int first1Bit(unsigned int n) {
    throw std::runtime_error("Not implemented!");
}
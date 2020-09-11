#include <cmath>
#include <gtest/gtest.h>

using namespace std;

// Написать реализацию функции возведения числа в степень
long long power(int, int);

#pragma region power tests

TEST(power, case1) {
    EXPECT_EQ(8, power(2, 3));
}

TEST(power, case2) {
    EXPECT_EQ(1, power(3, 0));
}

TEST(power, case3) {
    EXPECT_EQ(1125899906842624, power(2, 50));
}

TEST(power, case4) {
    EXPECT_EQ(-125, power(-5, 3));
}

TEST(power, case5) {
    EXPECT_EQ(81, power(-3, 4));
}

#pragma endregion

// todo
long long power(int, int) {
    throw std::runtime_error("Not implemented!");
}
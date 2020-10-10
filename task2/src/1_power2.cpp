#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

// Возвести 2 в степень n побитовыми операциями
unsigned long long power2(unsigned int n);

#pragma region power2 tests

TEST(power2, case1) {
    EXPECT_EQ(1, power2(0));
}

TEST(power2, case2) {
    EXPECT_EQ(1024, power2(10));
}

TEST(power2, case3) {
    EXPECT_EQ(pow(2, 63), power2(63));
}

#pragma endregion

// todo
unsigned long long power2(unsigned int n) {
    throw std::runtime_error("Not implemented!");
}
#include <gtest/gtest.h>
#include <string>
#include <stdexcept>

using namespace std;

// Перевести число из десятичной системы в двоичную с помощью битовых операций
string dec2bin(unsigned int n);

#pragma region dec2bin tests

TEST(dec2bin, case1) {
    EXPECT_EQ("", dec2bin(0));
}

TEST(dec2bin, case2) {
    EXPECT_EQ("100", dec2bin(4));
}

TEST(dec2bin, case3) {
    EXPECT_EQ("111", dec2bin(7));
}

TEST(dec2bin, case4) {
    EXPECT_EQ("1111111111111111111111111111111", dec2bin(INT32_MAX));
}

TEST(dec2bin, case5) {
    EXPECT_EQ("11111111111111111111111111110010", dec2bin(-14));
}

TEST(dec2bin, case6) {
    EXPECT_EQ("10000000000000000000000000000000", dec2bin(INT32_MIN));
}

#pragma endregion

// todo
string dec2bin(unsigned int n) {
    throw std::runtime_error("Not implemented!");
}
#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

/**
 * Проверяет, является ли строка правильной скобочной последовательностью
 * Пример правильной последовательности: "[()]{}"
 * Пример неправильной последовательности: "[(])"
 */
bool isCorrectBrackets(const string& brackets);

#pragma region isCorrectBrackets tests

TEST(isCorrectBrackets, case1) {
    string brackets = "[()]{}{[(())]()}";

    EXPECT_TRUE(isCorrectBrackets(brackets));
}

TEST(isCorrectBrackets, case2) {
    string brackets = "[(])";

    EXPECT_FALSE(isCorrectBrackets(brackets));
}

TEST(isCorrectBrackets, case3) {
    string brackets = "[()])";

    EXPECT_FALSE(isCorrectBrackets(brackets));
}

#pragma endregion

bool isCorrectBrackets(const string& brackets) {
    throw std::runtime_error("Not implemented!");
}
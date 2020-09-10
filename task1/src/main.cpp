/*
 * 1. Написать реализацию функции, вычисляющую сумму двух чисел (для этой функции также необходимо проверить,
 *    что сумма не превышает значение int, иначе бросить исключение)
 * 2. Написать реализацию функции возведения числа в степень
 * 3. Написать реализацию функции получения N-го числа Фибоначчи
 * 4. Написать реализацию функции проверки числа на простоту
 * 5. (*) Написать реализацию функции быстрого возведения числа в степень
 * 6. (**) Написать реализацию функции вычисления корня из числа без использования встроенной функции корня
 *         с точностью до 6 знаков после запятой
 */

#include <cmath>
#include <gtest/gtest.h>

using namespace std;

// Сумма
int sum(int, int);

// Возведение в степень
long long power(int, int);

// N-ое число Фибоначчи
long long fibonacci(int);

// Проверка на простоту
bool isPrime(int);

// Быстрое возведение в степень
long long binaryPower(int, int);

// Извлечение корня
double mySqrt(double);

#pragma region sum tests

TEST(sum, case1) {
    EXPECT_EQ(3, sum(1, 2));
}

TEST(sum, case2) {
    EXPECT_EQ(200, sum(100, 100));
}

TEST(sum, case3) {
    EXPECT_EQ(-15, sum(-5, -10));
}

TEST(sum, case4) {
    EXPECT_EQ(0, sum(1000, -1000));
}

TEST(sum, case5) {
    EXPECT_ANY_THROW(sum(INT32_MAX, 1));
}

TEST(sum, case6) {
    EXPECT_ANY_THROW(sum(INT32_MIN, -1));
}

#pragma endregion

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

#pragma region fibonacci tests

TEST(fibonacci, case1) {
    EXPECT_EQ(8, fibonacci(6));
}

TEST(fibonacci, case2) {
    EXPECT_EQ(1, fibonacci(2));
}

TEST(fibonacci, case3) {
    EXPECT_EQ(2, fibonacci(3));
}

TEST(fibonacci, case4) {
    EXPECT_EQ(55, fibonacci(10));
}

TEST(fibonacci, case5) {
    EXPECT_EQ(12586269025, fibonacci(55));
}

#pragma endregion

#pragma region isPrime tests

TEST(isPrime, case1) {
    EXPECT_FALSE(isPrime(1));
}

TEST(isPrime, case2) {
    EXPECT_TRUE(isPrime(2));
}

TEST(isPrime, case3) {
    EXPECT_TRUE(isPrime(3));
}

TEST(isPrime, case4) {
    EXPECT_FALSE(isPrime(25));
}

TEST(isPrime, case5) {
    EXPECT_TRUE(isPrime(197));
}

#pragma endregion

#pragma region binaryPower tests

TEST(binaryPower, case1) {
    EXPECT_EQ(8, binaryPower(2, 3));
}

TEST(binaryPower, case2) {
    EXPECT_EQ(1, binaryPower(3, 0));
}

TEST(binaryPower, case3) {
    EXPECT_EQ(1125899906842624, binaryPower(2, 50));
}

TEST(binaryPower, case4) {
    EXPECT_EQ(-125, binaryPower(-5, 3));
}

TEST(binaryPower, case5) {
    EXPECT_EQ(81, binaryPower(-3, 4));
}

#pragma endregion

#pragma region mySqrt tests

const static double ABS_ERROR = 1e-5;

TEST(mySqrt, case1) {
    const auto x = 2;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

TEST(mySqrt, case2) {
    const auto x = 9;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

TEST(mySqrt, case3) {
    const auto x = 100;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

TEST(mySqrt, case4) {
    const auto x = 12345678;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

TEST(mySqrt, case5) {
    const auto x = 1000000007;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

#pragma endregion


// todo: Реализовать функции
#include <iostream>

// ==============================================
// Фибоначчи
// ==============================================

template<int fib1 = 0, int fib2 = 1, int fibN = 5>
struct Fib;

template<int fib1, int fib2>
struct Fib<fib1, fib2, 1> {
    constexpr static auto next = fib1;
};

template<int fib1, int fib2, int fibN>
struct Fib {
    constexpr static auto next = Fib<fib2, fib1 + fib2, fibN - 1>::next;
};

constexpr auto fibonacci = Fib<0, 1, 6>::next;

// ==============================================
// Факториал
// ==============================================

template<int N>
struct Fac;

template<>
struct Fac<0> {
    constexpr static auto next = 1;
};

template<int N>
struct Fac {
    constexpr static auto next = N * Fac<N - 1>::next;
};

constexpr auto fac = Fac<5>::next;

int main() {
    using namespace std;

    cout << "fibonacci: " << fibonacci << endl;
    cout << "fac: " << fac << endl;

    return 0;
}
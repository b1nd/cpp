#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

long long sum() {
    int a, b;
    long long sum;
    do {
        cout << "Введите a и b: ";
        cin >> a >> b;
        sum = a + b;
    }
    while (sum >= INT_MAX);

    return a + b;
}

double pow(double num, int power) {
    double acc = num;
    for (int i = 0; i < power; i++)
        acc *= num;

    return acc;

}

long long fib(int a) {
    return a == 0 || a == 1
        ? 1 : fib(a - 1) + fib(a - 2);
}

bool isPrime(long long a) {
    for (int i = 2; i < sqrt(a); i++)
        if (a % i == 0 ) return false;

    return true;
}

double fastPow(double num, int power) {
    double acc = 1;
    if (!power) return 1;

    while (power) {
        if (power % 2 == 0) {
            power /= 2;
            acc *= acc;
        }
        else {
            --power;
            acc *= num;
        }
    }

    return acc;
}

double sqrt(int a) {
    double left = 1, right = __DBL_MAX__, mid = (left + right) / 2;
    while (abs(a - mid * mid) > 0.0001) {
        if (a > mid * mid)
            left = mid;
        else 
            right = mid;
        
        mid = (left + right) / 2;
    }

    return mid;
}

int main() {
    cout << sqrt(1);
    return 0;
}
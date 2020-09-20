#include <iostream>

class Counter {
public:
    explicit Counter(int sec) {
        seconds = sec;
    }

    Counter operator+(Counter other) const {
        return Counter(seconds + other.seconds);
    }

    // Не обязательно определять оператор на этот класс
    int operator+(int s) const {
        return this->seconds + s;
    }

    bool operator==(Counter other) const {
        return seconds == other.seconds;
    }

    Counter& operator++() {
        seconds += 5;
        return *this;
    }

    // Нужно вернуть ссылку на предыдущее значение!
    Counter operator++(int) {
        Counter prev = *this;
        ++*this;
        return prev;
    }

    // friend функция имеет доступ к приватным членам класса
    friend std::ostream& operator<<(std::ostream& out, const Counter& counter) {
        out << counter.seconds << " seconds";
        return out;
    }

private:
    int seconds;
};

int main() {
    using namespace std;

    Counter c1(20);
    Counter c2(10);
    Counter c3 = c1 + c2;

    cout << c3 << endl; // 30 seconds

    int seconds = c1 + 25;
    cout << "c1 + 25 = " << seconds << endl; // c1 + 25 = 45

    cout << "Counter(50) == Counter(50): " << (Counter(50) == Counter(50)) << endl;

    return 0;
}
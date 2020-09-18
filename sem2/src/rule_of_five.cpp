#include <algorithm>
#include <iostream>

class IntArray {
public:

    IntArray() {
        arr_ = nullptr;
        size_ = 0;
    }

    IntArray(const int ints[], size_t n) {
        size_ = n;
        arr_ = new int[n];

        for (int i = 0; i < n; ++i) {
            arr_[i] = ints[i];
        }
    }

    // Конструктор копирования
    IntArray(const IntArray& other) {
        std::cout << "Copy constructor call" << std::endl;
        size_ = other.size_;
        arr_ = new int[size_];

        for (size_t i = 0; i < size_; ++i) {
            arr_[i] = other.arr_[i];
        }
    }

    // Конструктор перемещения для rvalue (работает сильно быстрее)
    IntArray(IntArray&& other) noexcept {
        std::cout << "Swap constructor call" << std::endl;
        size_ = other.size_;
        arr_ = other.arr_;

        other.arr_ = nullptr;
    }

    // Деструктор, который освобождает выделенную память
    ~IntArray() {
        delete[] arr_;
    }

    // Оператор присваивания копированием
    IntArray& operator=(const IntArray& other) {
        std::cout << "Copy assigment operator call" << std::endl;
        IntArray tmp(other);
        swap(*this, tmp);

        return *this;
    }

    // Оператор присваивания перемещением для rvalue (работает сильно быстрее)
    IntArray& operator=(IntArray&& other) noexcept {
        std::cout << "Swap assigment operator call" << std::endl;
        swap(*this, other);
        other.arr_ = nullptr;

        return *this;
    }

private:

    static void swap(IntArray& left, IntArray& right) noexcept {
        std::swap(left.arr_, right.arr_);
        std::swap(left.size_, right.size_);
    }

    int size_;
    int* arr_;
};

int main() {
    int n = 3;
    int test[3] = {0, 1, 2};

    IntArray arr1(test, n);

    // Copy constructor
    IntArray arr2(arr1);
    // Swap constructor     // anonymous rvalue
    IntArray arr3(std::move(IntArray(test, n)));

    // Copy constructor
    IntArray arr4 = arr1;
    // Copy assigment operator
    arr4 = arr1;
    IntArray arr5;
    // Swap assigment operator
    arr5 = IntArray(test, n); // anonymous rvalue

    return 0;
}
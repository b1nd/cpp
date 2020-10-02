#include <iostream>
#include <cassert>

template<typename T, int size = 20>
class Array {
public:
    explicit Array(const T& defaultValue) {
        arr_ = new T[size];
        for (int i = 0; i < size; ++i) {
            arr_[i] = defaultValue;
        }
    }

    ~Array() {
        delete[] arr_;
    }

    T& operator[](int index) {
        assert(index >= 0 && index < size);
        return arr_[index];
    }

    const T& operator[](int index) const {
        assert(index >= 0 && index < size);
        return arr_[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const Array& arr) {
        for (int i = 0; i < size; ++i) {
            out << arr[i] << " ";
        }
        return out;
    }

private:
    T* arr_;
};

int main() {
    using namespace std;

    auto arr1 = Array<int>(0);
    arr1[1] = 1;
    arr1[2] = 2;

    auto arr2 = Array<string, 10>("abc");
    arr2[9] = "zxc";

    cout << arr1 << endl;
    cout << arr2 << endl;

    return 0;
}
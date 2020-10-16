#include <iterator>
#include <iostream>
#include <algorithm>

template<long FROM, long TO>
class Range {
public:
    class iterator {
        long num_ = FROM;
    public:
        explicit iterator(long num = 0) : num_(num) {}

        auto operator++() {
            num_ = TO >= FROM ? num_ + 1 : num_ - 1;
            return *this;
        }

        auto operator++(int) {
            iterator retval = *this;
            ++(*this);
            return retval;
        }

        bool operator==(iterator other) const { return num_ == other.num_; }

        bool operator!=(iterator other) const { return this->num_ != other.num_; }

        long operator*() { return num_; }

        const long operator*() const { return num_; }

        // iterator traits
        using difference_type = long;
        using value_type = long;
        using pointer = const long*;
        using reference = const long&;
        using iterator_category = std::forward_iterator_tag;
    };

    iterator begin() { return iterator(FROM); }

    iterator end() { return iterator(TO >= FROM ? TO + 1 : TO - 1); }
};

int main() {
    using namespace std;

    Range<5, 12> range;
    cout << "Range<5,12>:";
    // Работает с foreach
    for (auto el : range) {
        cout << " " << el;
    }
    cout << endl;

    // Работает с алгоритмами из std
    bool isTenInside = std::binary_search(begin(range), end(range), 10L);
    cout << "isTenInside: " << boolalpha << isTenInside << endl;
    auto maxElement = std::max_element(begin(range), end(range));
    cout << "maxElement: " << *maxElement << endl;

    return 0;
}
#include "Timer.h"

template<typename T>
long long Timer::result() const {
    if (triggered) {
        throw std::logic_error("Cannot get the result of working timer!");
    }
    return std::chrono::duration_cast<T>(endTime - startTime).count();
}

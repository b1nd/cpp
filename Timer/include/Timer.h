#ifndef CPP_TIMER_H
#define CPP_TIMER_H

#include <chrono>

/** \brief Simple timer provider. */
class Timer {

public:

    /** \brief Starts the timer. */
    void start();

    /** \brief Stops the timer. */
    void stop();

    /** \brief Gives result in std::chrono::T. */
    template<typename T = std::chrono::nanoseconds>
    long long result() const;

private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    bool triggered = false;
};

#include "Timer.hpp"

#endif //CPP_TIMER_H

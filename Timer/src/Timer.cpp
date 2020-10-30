#include "Timer.h"
#include <stdexcept>

void Timer::start() {
    triggered ? throw std::logic_error("The timer has already been started!") : triggered = true;
    startTime = std::chrono::steady_clock::now();
}

void Timer::stop() {
    !triggered ? throw std::logic_error("The timer has not been started yet!") : triggered = false;
    endTime = std::chrono::steady_clock::now();
}

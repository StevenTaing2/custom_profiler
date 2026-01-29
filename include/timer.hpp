#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <cstdio>

using timerClock = std::chrono::steady_clock;

class Timer {
public:
    Timer(const char* name) noexcept;
    ~Timer() noexcept;
private:
    uint64_t startTime_;
    const char* name_;
};

#endif

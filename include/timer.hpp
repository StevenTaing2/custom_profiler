#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <cstdio>

using timerClock = std::chrono::steady_clock;

class Timer {
public:
    Timer(const char* name);
    ~Timer();
private:
    std::chrono::time_point<timerClock> startTime_;
    uint64_t finalDuration_;
    const char* name_;
};

#endif

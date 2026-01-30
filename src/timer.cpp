#include "timer.hpp"
#include "collector.hpp"

using namespace std;

static const uint64_t startNs = []() {
    return chrono::duration_cast<chrono::nanoseconds>(
        timerClock::now().time_since_epoch()
    ).count();
}();

static inline uint64_t nowNs() noexcept {
    return chrono::duration_cast<chrono::nanoseconds>(
        timerClock::now().time_since_epoch()
    ).count() - startNs;
}

Timer::Timer(const char* name) noexcept :
    startTime_ {nowNs()},
    name_ {name}
{
    Collector::recordEventBegin(name_, startTime_);
}

Timer::~Timer() noexcept {
    Collector::recordEventEnd(name_, nowNs());
}

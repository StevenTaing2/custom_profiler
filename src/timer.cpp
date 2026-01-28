#include <timer.hpp>

using namespace std;

Timer::Timer(const char* name) :
    startTime_ {timerClock::now()},
    name_ {name}
{
}

Timer::~Timer(){
    auto end = timerClock::now();
    finalDuration_ = std::chrono::duration_cast<std::chrono::milliseconds>(end - startTime_).count();
}

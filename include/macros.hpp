#pragma once

#if ENABLE_PROFILING

#include "timer.hpp"

#define PROFILE_SCOPE(name) \
    Timer scopeTimer_##__LINE__(name)

#else

#define PROFILE_SCOPE(name) \
    ((void)0)

#endif

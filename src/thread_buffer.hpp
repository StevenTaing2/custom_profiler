#ifndef THREAD_BUFFER_HPP
#define THREAD_BUFFER_HPP

#include <cstdio>
#include <cstdint>

constexpr uint32_t MAX_EVENTS = 1 << 16;

struct Event {
    const char* name;
    uint64_t timestamp;
    uint32_t threadId;
    char phase;
};

struct ThreadBuffer {
    Event events[MAX_EVENTS];
    uint32_t writeIndex = 0;
};

extern thread_local ThreadBuffer g_threadBuffer;

#endif

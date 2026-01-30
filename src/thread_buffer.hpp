#ifndef THREAD_BUFFER_HPP
#define THREAD_BUFFER_HPP

#include <cstdio>
#include <cstdint>
#include <vector>
#include <mutex>

constexpr uint32_t MAX_EVENTS = 1 << 16;
constexpr uint32_t MAX_THREADS = 128;   // configurable

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

extern ThreadBuffer g_threadBuffers[MAX_THREADS];
extern std::atomic<uint32_t> g_threadCount;

extern thread_local ThreadBuffer* g_threadBuffer;
#endif

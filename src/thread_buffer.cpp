#include "thread_buffer.hpp"
#include <cassert>

ThreadBuffer g_threadBuffers[MAX_THREADS];
std::atomic<uint32_t> g_threadCount{0};

thread_local ThreadBuffer* g_threadBuffer = [] {
    uint32_t index = g_threadCount.fetch_add(1, std::memory_order_relaxed);
    assert(index < MAX_THREADS && "Exceeded max profiler threads");

    return &g_threadBuffers[index];
}();

#include "collector.hpp"
#include "thread_buffer.hpp"
#include <thread>

using namespace std;

static inline uint32_t getThreadId() noexcept {
    static thread_local uint32_t id = static_cast<uint32_t>(hash<thread::id>{}(std::this_thread::get_id()));
    return id;
}

void Collector::recordEventBegin(const char* name, uint64_t timestamp) noexcept {
    auto& buf = *g_threadBuffer;

    if (buf.writeIndex >= MAX_EVENTS){
        return;
    }

    buf.events[buf.writeIndex++] = {
        name,
        timestamp,
        getThreadId(),
        'B'
    };
}

void Collector::recordEventEnd(const char* name, uint64_t timestamp) noexcept {
    auto& buf = *g_threadBuffer;

    if (buf.writeIndex >= MAX_EVENTS){
        return;
    }

    buf.events[buf.writeIndex++] = {
        name,
        timestamp,
        getThreadId(),
        'E'
    };
}

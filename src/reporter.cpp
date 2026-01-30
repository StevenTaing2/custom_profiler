#include "reporter.hpp"
#include <fstream>
#include "thread_buffer.hpp"

static inline uint64_t toMicroseconds(uint64_t ns) noexcept {
    return ns / 1000;
}

void Reporter::writeToChromeTrace(const char* filename) {
    std::ofstream out(filename);
    out << "{ \"traceEvents\": [\n";

    bool first = true;

    for (uint32_t t = 0; t < g_threadCount.load(); ++t) {
        const ThreadBuffer& buf = g_threadBuffers[t];

        for (uint32_t i = 0; i < buf.writeIndex; ++i) {
            const Event& e = buf.events[i];

            if (!first) out << ",\n";
            first = false;

            out << "  {"
                << "\"name\":\"" << e.name << "\","
                << "\"ph\":\"" << e.phase << "\","
                << "\"ts\":" << toMicroseconds(e.timestamp) << ","
                << "\"pid\":0,"
                << "\"tid\":" << e.threadId
                << "}";
        }
    }

    out << "\n] }\n";
}

#ifndef COLLECTOR_HPP
#define COLLECTOR_HPP

#include <cstdint>

struct Event;

class Collector {
public: 
    static void recordEventBegin(const char* name, uint64_t timestamp) noexcept;
    static void recordEventEnd(const char* name, uint64_t timestamp) noexcept;
};

#endif

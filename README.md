# Custom RAII-Based Scope Profiler
This project implements a lightweight, zero-allocation, RAII-based CPU scope profiler designed for high-performance multithreaded applications. It aims to provide precise, low-overhead profiling by measuring code scopes with simple macros, outputting data compatible with Chrome Trace format.

## Features
- **RAII-based Scope Timing** — automatic start/end timing via C++ object lifetime.
- **Zero heap allocations** during profiling — uses fixed-size thread-local ring buffers.
- **Minimal overhead** — avoids locks, mutexes, and dynamic memory.
- **Thread-safe and multithreaded** — each thread has its own event buffer.
- **Compile-time enable/disable** using macros and compiler flags.
- **Chrome Trace JSON output** compatible for visualization in Chrome's built-in profiler.
- **Simple instrumentation macros** for easy adoption into other projects.


## Building the Profiler
### Clone and Build
```
git clone <repository-url>
cd profiler

mkdir build
cd build

cmake -DENABLE_PROFILING=ON ..
cmake --build .
```
### Using the profiler in your project
#### Include the Profiling Macros
```
#include "macros.hpp"
```
#### Profile a Scope
```
void exampleFunction() {
    PROFILE_SCOPE("exampleFunction");

    // Code to measure
}
```
#### Nested Scopes
```
void work() {
    PROFILE_SCOPE("outer");

    {
        PROFILE_SCOPE("inner");
        // Nested work
    }
}
```
#### Profile an Entire Function
```
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)
```
#### Creating the Trace Output
```
#include "reporter.hpp"

Reporter::writeToChromeTrace("trace.json");
```
### Viewing Results in Chrome Trace Viewer
1. Open Google Chrome
2. Navigate to: chrome://tracing
3. Load the generated trace.json file

4. The viewer will display:
- Nested scope hierarchies
- Parallel execution across threads
- The beginning and end of events

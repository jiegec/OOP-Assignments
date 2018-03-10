#ifndef _WIN32
#include <chrono>

std::chrono::high_resolution_clock::time_point begin_time;

void timer_begin() { begin_time = std::chrono::high_resolution_clock::now(); }

double timer_end() {
  auto current_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(current_time -
                                                               begin_time)
    .count();
}

#else

#include <windows.h>

LARGE_INTEGER winFreq;
LARGE_INTEGER winStart;

void timer_begin() {
  QueryPerformanceFrequency(&winFreq);
  QueryPerformanceCounter(&winStart);
}

double timer_end() {
  LARGE_INTEGER winNow;
  QueryPerformanceCounter(&winNow);
  return (double)(winNow.QuadPart - winStart.QuadPart) / (double)winFreq.QuadPart;
}

#endif

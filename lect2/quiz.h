#pragma once
#include <chrono>

class BenchGuard {
public:
    BenchGuard();
    ~BenchGuard();

private:
    std::chrono::time_point<std::chrono::steady_clock> start;
};

unsigned long long fibonacci(int n);

void bench();

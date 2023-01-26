#include "quiz.h"
#include <chrono>
#include <iostream>

BenchGuard::BenchGuard()
: start(std::chrono::steady_clock::now()) {
}

BenchGuard::~BenchGuard() {
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Elapsed time: " << diff.count() << " seconds\n";
}

unsigned long long fibonacci(int n) {
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void bench() {
    BenchGuard _;
    fibonacci(25);
}

#include <iostream>
#include <memory>
#include <mutex>
#include "box.h"
#include "guard.h"
#include "quiz.h"

std::mutex mutex;
int i = 10;

void test_box() {
    Box<int> i{ new int };
    std::cout << i.get() << '\n';

    // int a[100000000]; // error: too large

    Box<int> a{ new int[100000000] };
    std::cout << a.get() << '\n';
}

void test_guard() {
    std::cout << "before guard\n";
    CoutGuard _;
    std::cout << "after guard\n";
}

void test_unique_ptr() {
    std::unique_ptr<int> i = std::make_unique<int>(10);
    std::cout << *i << '\n';
    *i = 100;
    std::cout << *i << '\n';
}

void test_mutex_guard() {
    std::lock_guard<std::mutex> lock(mutex);
    std::cout << "Use i\n";
    i += 1;
}

int main() {
    bench();
    return 0;
}

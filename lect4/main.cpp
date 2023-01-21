#include <iostream>
#include <mutex>
#include <semaphore>
#include <thread>

// std::mutex mutex;
std::counting_semaphore<1> mutex(1);
int N;

// Function Pointer
void f1() {
    for (int i = 0; i < 5; i += 1) {
        // mutex.lock();
        std::cout << "f1();\n";
        // mutex.unlock();
    }
}

// Functor
struct f2 {
    void operator()(int n) {
        for (int i = 0; i < 5; i += 1) {
            // std::lock_guard<std::mutex> lock(mutex);
            std::cout << "f2(" << n << ");\n";
        }
    }
};

// Lambda
auto f3 = [](int n, int m) {
    for (int i = 0; i < 5; i += 1) {
        // std::lock_guard<std::mutex> lock(mutex);
        std::cout << "f3(" << n << ", " << m << ");\n";
    }
};

void sum(int a, int b) {
    for (int n = a; n < b; n += 1) {
        mutex.acquire();
        N += n;
        mutex.release();
    }
}

int main() {
    std::thread t1(sum, 0, 25);
    std::thread t2(sum, 25, 50);
    std::thread t3(sum, 50, 75);
    std::thread t4(sum, 75, 101);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    std::cout << N;
    return 0;
}

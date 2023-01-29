#pragma once
#include <mutex>
#include <queue>

template<typename T>
class MutexQueue {
public:
    MutexQueue() = default;

    explicit MutexQueue(std::queue<T> queue)
    : queue(queue) {}

    int size() const {
        return queue.size();
    }

    T pop() {
        std::lock_guard<std::mutex> lock(mutex);
        const T value = queue.front();
        queue.pop();
        return value;
    }

    void push(T value) {
        std::lock_guard<std::mutex> lock(mutex);
        queue.push(value);
    }

private:
    std::mutex mutex;
    std::queue<T> queue;
};

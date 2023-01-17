#pragma once

template<typename T>
class Box {
public:
    explicit Box(T *ptr)
    : ptr(ptr) {}

    T *get() const {
        return ptr;
    }

    ~Box() {
        delete[] ptr;
    }

private:
    T *ptr;
};

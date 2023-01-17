#pragma once
#include <iostream>

class CoutGuard {
public:
    CoutGuard() {
        std::cout << "{\n";
    }

    ~CoutGuard() {
        std::cout << "}\n";
    }
};

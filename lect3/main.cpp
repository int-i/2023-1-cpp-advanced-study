#include <algorithm>
#include <functional>
#include <iostream>

bool compare(int a, int b) {
    return a > b;
}

struct Compare {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main2() {
    int A[10] = { 3, 6, 5, 8, 2, 1, 0, 7, 9, 4 };

    // 오름차순
    std::sort(A, A + 10);
    for (int i : A) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 내림차순: Function Pointer
    std::sort(A, A + 10, compare);
    for (int i : A) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    int B[10] = { 1, 0, 2, 5, 8, 9, 4, 7, 3, 6 };

    // 내림차순: Functor
    std::sort(B, B + 10, Compare());
    for (int i : B) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 내림차순: STL Functor
    std::sort(B, B + 10, std::greater<int>());
    for (int i : B) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    int C[10] = { 5, 8, 2, 4, 7, 0, 6, 3, 9, 1 };

    // 내림차순: Lambda
    std::sort(C, C + 10, [](int a, int b) {
        return a > b;
    });
    for (int i : C) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // Lambda
    auto addmul = [](int a, int b, int c) {
        return a + b * c;
    };
    int i = addmul(1, 2, 3);

    // Lambda + Closure
    int n = 5;
    auto addn = [n](int a, int b) -> int {
        return a + b + n;
    };
    int j = addn(1, 2);
    return 0;
}

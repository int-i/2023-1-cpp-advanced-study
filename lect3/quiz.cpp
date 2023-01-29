#include <iostream>
#include <queue>
#include <vector>

struct OddFirst {
    bool operator()(int a, int b) const {
        if (a % 2 == 0) {
            if (b % 2 == 0) {
                return a < b; // a짝 b짝
            }
            return true; // a짝 b홀
        }
        if (b % 2 == 0) {
            return false; // a홀 b짝
        }
        return a > b; // a홀 b홀
    }
};

int main() {
    int A[10] = { 3, 6, 5, 8, 2, 1, 0, 7, 9, 4 };

    std::cout << "A: ";
    for (int i : A) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::priority_queue<int, std::vector<int>, OddFirst> pq(A, A + 10);

    pq.push(15);
    pq.push(-3);
    pq.push(13);
    pq.push(14);
    pq.push(-2);
    pq.push(11);
    pq.push(-4);
    pq.push(-5);
    pq.push(12);
    pq.push(-1);

    std::cout << "pq: ";
    while (!pq.empty()) {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
    std::cout << '\n';
    return 0;
}
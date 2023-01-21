#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int A[10] = { 3, 6, 5, 8, 2, 1, 0, 7, 9, 4 };

    std::cout << "A: ";
    for (int i : A) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 오름차순 우선순위 큐
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(A, A + 10);

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
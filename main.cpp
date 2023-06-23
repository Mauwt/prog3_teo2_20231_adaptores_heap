#include <iostream>
#include <vector>
#include "cola_priorizada.h"

int main() {
    utec::priority_queue<int> pq1;
    pq1.push(1);
    pq1.emplace(20);
    pq1.emplace(50);
    pq1.push(8);
    pq1.push(60);
    pq1.emplace(70);
    pq1.emplace(3);
    while(!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    vector v = {1, 20, 50, 8, 60, 70, 3};
    utec::priority_queue<int, vector<int>, greater<>> pq2(v);
    while(!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;
    return 0;
}

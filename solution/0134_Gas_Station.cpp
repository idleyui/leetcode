#include "alg.h"

int canCompleteCircuit(vector<int> gas, vector<int> cost) {
    int n = gas.size();
    vector<int> surplus(n, 0);
    for (int i = 0; i < n; i++) surplus[i] = gas[i] - cost[i];

    int i = 0;
    for (; i < n; ++i) {
        if (surplus[i] < 0)continue;
        int plus = surplus[i];
        int cur = i + 1;
        for (; cur % n != i; ++cur) {
            plus += surplus[cur % n];
            if (plus < 0) break;
        }
        if (cur % n == i)return i;
    }
    return -1;
}

int main() {
    cout << canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2});
    cout << canCompleteCircuit({2, 3, 4}, {3, 4, 3});
}
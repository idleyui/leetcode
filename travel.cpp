#include "alg.h"

int main() {
    int n;
    cin >> n;
    vector<int> cities(n + 1);
//    vector<int> from[n - 1];
//    vector<int> to[n - 1];

    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        cin >> from >> to;
        cities[to] = from;

    }
}
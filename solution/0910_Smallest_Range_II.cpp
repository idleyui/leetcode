#include "alg.h"

// https://leetcode.com/problems/smallest-range-ii/discuss/173377/C%2B%2BJavaPython-Add-0-or-2-*-K
int smallestRangeII(vector<int> A, int K) {
    sort(A.begin(), A.end());
    int n = A.size(), mx = A[n - 1], mn = A[0], res = mx - mn;
    for (int i = 0; i < n - 1; ++i) {
        mx = max(mx, A[i] + 2 * K);
        mn = min(A[i + 1], A[0] + 2 * K);
        res = min(res, mx - mn);
    }
    return res;
}

int main() {
    cout << smallestRangeII({7, 8, 8, 5, 2}, 4) << endl;
    cout << smallestRangeII({2, 7, 2}, 1) << endl;
    cout << smallestRangeII({4, 8, 2, 7, 2}, 5) << endl;
    cout << smallestRangeII({1}, 0) << endl;
    cout << smallestRangeII({0, 10}, 2) << endl;
    cout << smallestRangeII({1, 3, 6}, 3) << endl;
    cout << smallestRangeII({1, 3, 6}, 2) << endl;
    cout << smallestRangeII({1, 3, 6}, 5) << endl;
    cout << smallestRangeII({1, 3, 6}, 10) << endl;
}
#include "alg.h"

vector<int> dp;

int sq(int n) {
    if (n <= 0) return 0;
    if (dp[n - 1] > 0) return dp[n - 1];
    int _min = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int square = i * i;
        if (square > n) break;
        int rt = sq(n - i * i) + 1;
        _min = min(_min, rt);
    }
    dp[n - 1] = _min;
    return _min;
}

int numSquares(int n) {
    dp = vector<int>(n, 0);
    return sq(n);
}

int main() {
    for(int i = 0; i < 12; i++)
        cout << i << ' ' << numSquares(i) << ',';

}
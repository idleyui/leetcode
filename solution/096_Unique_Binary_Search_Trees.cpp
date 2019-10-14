#include "alg.h"

int numTrees(int n, vector<int> &dp) {
    if (dp[n] > 0) return dp[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numTrees(i, dp) * numTrees(n - 1 - i, dp);
    }
    dp[n] = sum;
    return sum;
}

int numTrees(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    return numTrees(n, dp);
}

int main() {
    for (int i = 0; i < 10; ++i) {
        cout << numTrees(i) << endl;
    }
}
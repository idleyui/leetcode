#include "alg.h"

int integerBreak(int n) {
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int left = 1; left < i; left++) {
            dp[i] = max(dp[i], max(dp[left], left) * max(dp[i - left], i - left));
        }
    }
    return dp[n];
}

int main() {

}

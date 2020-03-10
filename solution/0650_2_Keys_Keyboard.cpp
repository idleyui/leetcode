#include "alg.h"

int minSteps_1(int n) {
    int steps = 0;
    while (n > 1) {
        for (int i = n / 2; i >= 1; i--) {
            if (n % i == 0) {
                steps += n / i;
                n = i;
                break;
            }
        }
    }
    return steps;
}

// https://leetcode.com/problems/2-keys-keyboard/discuss/105897/Loop-best-case-log(n)-no-DP-no-extra-space-no-recursion-with-explanation
int minStep_1_(int n) {
    int step = 0;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            step += i;
            n /= i;
        }
    }
    return step;
}

// dp
int minSteps_2(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (i % j == 0) {
                dp[i] = dp[j] * (i / j);
                break;
            }
        }
    }
    return dp[n];
}

int main() {

}
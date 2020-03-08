#include "alg.h"


int numRollsToTarget(int d, int f, int target) {
    vector<long> dp(target + 1, 0);
    for (int i = 1; i <= f && i <= target; i++) dp[i] = 1;
    for (int i = 1; i < d; i++) {
        for (int j = target; j >= 0; j--) {
            dp[j] = 0;
            for (int k = 1; k <= f; k++) {
                if (j - k < 0) { break; }
                dp[j] += dp[j - k];
                dp[j] %= (1000000000 + 7);
            }
        }
    }
    return dp[target];
}

int main() {

}
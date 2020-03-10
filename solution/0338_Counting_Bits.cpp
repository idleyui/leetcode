#include "alg.h"

vector<int> countBits(int num) {
    if (num == 0)return {0};
    vector<int> dp(num + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    int ex2 = 2;
    for (int i = 2; i <= num; i++) {
        if (i % ex2 == 0) {
            ex2 = i;
            dp[i] = 1;
        } else {
            dp[i] = 1 + dp[i - ex2];
        }
    }
    return dp;
}

int main() {

}
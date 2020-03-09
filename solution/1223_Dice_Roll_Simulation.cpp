#include "alg.h"

int dfs(vector<int> &rollMax, int last, int last_cnt, int n) {
    if (n == 0) return 1;
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        if (i == last) {
            if (rollMax[i] - last_cnt == 0) continue;
            sum += dfs(rollMax, i, last_cnt + 1, n - 1);
        } else {
            sum += dfs(rollMax, i, 1, n - 1);
        }
    }
    return sum;
}

int dieSimulator(int n, vector<int> &rollMax) {
    return dfs(rollMax, -1, 0, n);
}

int MOD = 1000000000 + 7;

int dfs(vector<vector<vector<int>>> &dp,
        vector<int> &rollMax, int last, int last_cnt, int n) {
    if (n == 0) return 1;
    if (last >= 0 && dp[last][last_cnt][n] >= 0) return dp[last][last_cnt][n];
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        if (i == last) {
            if (rollMax[i] - last_cnt == 0) continue;
            sum += dfs(dp, rollMax, i, last_cnt + 1, n - 1);
        } else {
            sum += dfs(dp, rollMax, i, 1, n - 1);
        }
        sum %= MOD;
    }
    if (last >= 0) dp[last][last_cnt][n] = sum;
    return sum;
}

int dieSimulator_2(int n, vector<int> &rollMax) {
    vector<vector<vector<int>>> dp(6, vector<vector<int>>(16,
                                                          vector<int>(5001, -1)));
    return dfs(dp, rollMax, -1, 0, n);
}

int main() {

}
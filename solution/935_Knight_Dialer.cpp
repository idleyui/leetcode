#include "alg.h"

vector<vector<int>> next = {{4, 6},
                            {6, 8},
                            {7, 9},
                            {4, 8},
                            {3, 9, 0},
                            {},
                            {1, 7, 0},
                            {2, 6},
                            {1, 3},
                            {2, 4}};

int dfs(vector<vector<int>> &dp, int num, int N) {
    if (N == 0) return 1;
    if (dp[num][N] != -1) return dp[num][N];
    int sum = 0;
    for (int i: next[num]) {
        sum += dfs(dp, i, N - 1);
        sum %= (1000000000 + 7);
    }
    dp[num][N] = sum;
    return sum;
}

int knightDialer(int N) {
    vector<vector<int>> dp(10, vector<int>(N + 1, -1));
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dfs(dp, i, N - 1);
        sum %= (1000000000 + 7);
    }
    return sum;
}

int main() {

}
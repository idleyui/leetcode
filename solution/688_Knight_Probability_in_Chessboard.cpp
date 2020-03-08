#include "alg.h"

double dfs(vector<vector<vector<double>>> &dp, int N, int K, int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= N) { return 0; }
    if (K == 0) { return 1; }
    if (dp[r][c][K] > 0) { return dp[r][c][K]; }
    double sum = 0;
    sum += dfs(dp, N, K - 1, r - 2, c + 1);
    sum += dfs(dp, N, K - 1, r - 1, c + 2);
    sum += dfs(dp, N, K - 1, r + 1, c + 2);
    sum += dfs(dp, N, K - 1, r + 2, c + 1);
    sum += dfs(dp, N, K - 1, r + 2, c - 1);
    sum += dfs(dp, N, K - 1, r + 1, c - 2);
    sum += dfs(dp, N, K - 1, r - 1, c - 2);
    sum += dfs(dp, N, K - 1, r - 2, c - 1);
    dp[r][c][K] = sum / 8;
    return dp[r][c][K];
}

double knightProbability(int N, int K, int r, int c) {
    vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K + 1, -1)));
    return dfs(dp, N, K, r, c);
}

int main() {

}
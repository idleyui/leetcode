#include "alg.h"

// https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] != text2[j - 1]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    return dp[n][m];
}

int longestCommonSubsequence_2(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(2, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            else dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
        }
    }
    return dp[1][m];
}

int main() {

}
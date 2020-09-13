#include "alg.h"

// 1143 lcs
int lcs(string &s1, string &s2) {
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int longestPalindromeSubseq(string s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    return lcs(s, rs);
}

int main() {

}
#include "alg.h"


bool isScramble(string s1, string s2) {
    int m = s1.size();
    if (m == 0) return true;
    if (m == 1) return s1 == s2;
    int dp[m + 1][m][m] = {0};

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            dp[1][i][j] = s1[i] == s2[i];

    for (int len = 2; len <= m; len++) {
        for (int i = 0; i <= m - len; i++) {
            for (int j = 0; j <= m - len; j++) {
                for(int k = 0; k < len && !dp[len][i][j]; k++){
                    dp[len][i][j] = dp[len][i][j] || (dp[k][i][j] && dp[len-k][i+k][j+k]);
                    dp[len][i][j] = dp[len][i][j] || (dp[k][i+len-k][j] && dp[len-k][i][j+k]);
                }
            }
        }
    }
    return dp[m][0][0];
}

int main() {
    cout << isScramble("great", "rgeat");
}
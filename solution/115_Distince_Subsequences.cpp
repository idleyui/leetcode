#include "alg.h"

int numDistinct(string s, string t) {
    int dp[s.size() + 1][t.size() + 1] = {0};

    for (int i = 1; i < s.size() + 1; i++) {
        for (int j = 1; j < t.size() + 1 && j <= i; j++) {
            if (j == 1 && s[i - 1] == t[0]) dp[i][j] = dp[i - 1][j] + 1;
            else if (j == 1 && s[i - 1] != t[0]) dp[i][j] = dp[i - 1][j];
            else if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i-1][j - 1] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[s.size()][t.size()];
}

int main() {
    cout << numDistinct("rabbbit", "rabbit");
    cout << numDistinct("babba", "ba");
    cout << numDistinct("babgbag", "bag");
}
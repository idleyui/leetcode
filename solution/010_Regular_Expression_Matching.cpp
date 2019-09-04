#include "alg.h"

bool match(char c, char p) {
    return p == '.' or c == p;
}

bool isMatch(string s, string p) {
    vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, 0));

    dp[0][0] = 1;
    for (int i = 0; i < p.size(); ++i) {
        for (int j = 0; j <= s.size(); ++j) {
            if (p[i] != '*') {
                if (j == s.size()) continue;
                bool m = match(s[j], p[i]);
                if (!m) continue;
                dp[i + 1][j + 1] = dp[i][j];
            } else { //*
                dp[i + 1][j] = dp[i - 1][j];
                if (!dp[i - 1][j]) continue;
                int k = j + 1;
                for (; k <= s.size() && match(s[k-1], p[i - 1]); k++)
                    dp[i + 1][k] = 1;
                j = k - 1;
            }
        }
    }
    return dp[p.size()][s.size()] == 1;
}

int main() {

    cout << isMatch("aa", "a");
    cout << isMatch("aa", "a*");
    cout << isMatch("aa", ".*");
    cout << isMatch("aab", "c*a*b");
    cout << isMatch("mississippi", "mis*is*p*");
    cout << isMatch("aaa", "ab*ac*a");
    cout << isMatch("aaa", "ab*a*c*a*");
    cout << endl;
    cout << "0111011";
}
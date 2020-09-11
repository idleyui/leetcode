#include "alg.h"

// dp
int countSubstrings(string s) {
    int n = s.size(), cnt = n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            cnt++;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            if (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2]) {
                dp[i][i + len - 1] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int exp(string &s, int l, int r) {
    int cnt = 0;
    for (; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++) cnt++;
    return cnt;
}

// exp
int countSubstrings_2(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        cnt += exp(s, i, i);
        cnt += exp(s, i, i + 1);
    }
    return cnt + 1;
}

int main() {

}
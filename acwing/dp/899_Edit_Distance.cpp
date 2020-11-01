#include<iostream>

using namespace std;

const int N = 1010;
int dp[N][N];
string S[N];

int editDistance(string &s1, string &s2, int n, int m) {
    //memset(dp, 0, sizeof dp);
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 0; i <= n; i++) dp[i][0] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }

    while (m--) {
        string s;
        int minDist, cnt = 0;
        cin >> s >> minDist;
        for (int i = 0; i < n; i++) {
            if (editDistance(S[i], s, S[i].size(), s.size()) <= minDist) cnt++;
        }
        cout << cnt << endl;
    }
}

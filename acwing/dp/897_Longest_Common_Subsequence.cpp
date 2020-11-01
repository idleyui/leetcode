#include<iostream>

using namespace std;

const int N = 1010;
int n, m;
int dp[N][N];
string s1, s2;

int lcs() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    return dp[n][m];
}

int main() {
    cin >> n >> m;
    cin >> s1 >> s2;
    cout << lcs();
}
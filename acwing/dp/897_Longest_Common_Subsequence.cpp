#include<iostream>

using namespace std;

const int N = 1010;
int n, m;
int dp[N][N];
string s1, s2;

// 以 A[i], B[j] 是否包含在子序列中为划分，因此有四种情况
int lcs() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            // 01 00 10 00
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            // 11
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
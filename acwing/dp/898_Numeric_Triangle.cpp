#include <iostream>
#include <cstring>

using namespace std;

const int N = 520, INF = -1e9;
int n;
int A[N][N];

int maxPath_naive() {
    int dp[N][N];
    memset(dp, 0x80, sizeof dp);
    dp[1][1] = A[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + A[i][j];
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    return ans;
}

int maxPath() {
    int dp[N];
    for (int i = 0; i < N; i++) dp[i] = INF;
    dp[1] = A[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 2; j--) {
            dp[j] = max(dp[j], dp[j - 1]) + A[i][j];
        }
        dp[1] += A[i][1];
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> A[i][j];
        }
    }
    cout << maxPath();
}

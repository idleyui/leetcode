#include <vector>
#include <iostream>

using namespace std;

const int N = 1010;
int dp[N][N];
int v[N], w[N], s[N];
int n, m;

int unbounded() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k <= s[i] && k * v[i] <= j; ++k) {
                dp[i][j] = max(dp[i - 1][j - v[i] * k] + w[i] * k, dp[i][j]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i] >> s[i];
    }
    cout << unbounded();
}

#include <vector>
#include <iostream>

using namespace std;

const int N = 110;
int dp[N][N], S[N];
int v[N][N], w[N][N];
int n, m;

int multiple_knapsack() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= S[i]; ++k) {
                if (j >= v[i][k])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> S[i];
        for (int j = 1; j <= S[i]; ++j) {
            cin >> v[i][j] >> w[i][j];
        }
    }
    cout << multiple_knapsack();
}

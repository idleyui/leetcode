#include <vector>
#include <iostream>

using namespace std;

const int N = 1010;
int dp[N];
int v[N], w[N];
int n, m;

int zero_one_naive() {
    int naive_dp[N][N];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            naive_dp[i][j] = naive_dp[i - 1][j];
            if (j >= v[i]) naive_dp[i][j] = max(naive_dp[i][j], naive_dp[i - 1][j - v[i]] + w[i]);
        }
    }
    return naive_dp[n][m];
}

int zero_one() {
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= v[i]; ++j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    return dp[m];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }
    cout << zero_one();
}

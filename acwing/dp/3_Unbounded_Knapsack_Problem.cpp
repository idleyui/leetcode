#include <vector>
#include <iostream>

using namespace std;

const int N = 1010;
//int dp[N][N];
int dp[N];
int v[N], w[N];
int n, m;

int unbounded() {
    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//        }
//      from v[i] to m
        for (int j = v[i]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
//    return dp[n][m];
    return dp[m];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }
    cout << unbounded();
}

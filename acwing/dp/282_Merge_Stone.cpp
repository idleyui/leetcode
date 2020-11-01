#include<iostream>
#include<climits>

using namespace std;

const int N = 315;
int n;
int A[N], SUM[N];
int dp[N][N];

int sum(int l, int r) {
    return SUM[r] - SUM[l - 1];
}

int minPrice() {
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; ++i) {
            dp[i][i + len - 1] = INT_MAX;
            for (int left = 1; left < len; left++) {
                int v = dp[i][i + left - 1]
                        + dp[i + left][i + len - 1]
                        + sum(i, i + left - 1)
                        + sum(i + left, i + len - 1);
                if (v < dp[i][i + len - 1]) {
                    dp[i][i + len - 1] = v;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        SUM[i] = A[i];
        SUM[i] += SUM[i - 1];
    }
    cout << minPrice();
}
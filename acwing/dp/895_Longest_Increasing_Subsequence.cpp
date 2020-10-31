#include <iostream>

using namespace std;

const int N = 1010;
int n;
int A[N];
int dp[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> A[i]; }

    int res = 0;
    // init dp[N] here will not be set all 0
    // int dp[N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += 1;
        res = max(res, dp[i]);
    }

    cout << res;
}
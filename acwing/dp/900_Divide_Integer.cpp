#include<iostream>

using namespace std;

const int N = 1010;
int dp[N][N];

int divideInteger(int n, int base) {
    if (n == 0) return 1;
    if (dp[n][base]) return dp[n][base];
    int cnt = 0;
    for (int i = base; i <= n; i++) {
        cnt += divideInteger(n - i, i);
        cnt = cnt % (int) (1e9 + 7);
    }
    dp[n][base] = cnt;
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << divideInteger(n, 1);
}
#include <vector>
#include <iostream>

using namespace std;

const int N = 25000, M = 2010;
int dp[M];
int v[N], w[N];
int n, m;

int zero_one() {
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    return dp[m];
}

int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s) {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0) {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;
    cout << zero_one();
}

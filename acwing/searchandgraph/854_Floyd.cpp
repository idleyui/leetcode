// https://www.acwing.com/problem/content/852/
#include<cstring>
#include<iostream>
#include<queue>
#include <climits>

using namespace std;

const int N = 510, INF = 1e9;

int n, m, k;
int h[N][N];

// d[k, i, j] min path from i (through {1...k}) to j
// d[k, i, j] = d[k-1, i, k] + d[k-1, k, j]
int floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) h[i][j] = 0;
            else h[i][j] = INF;
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        h[a][b] = min(h[a][b], c);
    }

    floyd();

    while (k--) {
        int a, b;
        cin >> a >> b;
        int t = h[a][b];
        if (t > INF / 2) cout << "impossible";
        else cout << t;
        cout << endl;
    }
}


// https://www.acwing.com/problem/content/852/
#include<cstring>
#include<iostream>
#include<queue>
#include <climits>

using namespace std;

const int N = 510, M = 1, INF = 0x3f;

int n, m, k;
int h[N][N];
//int h[N], e[M], ne[M], d[M], idx;
int dist[N], st[N];

//void add(int a, int b, int c) {
//    e[idx] = b, ne[idx] = h[a], d[idx] = c, h[a] = idx++;
//}


void prim() {
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int min_i = 0;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && dist[j] < dist[min_i]) min_i = j;
        }
        if (min_i == 0) break;
        st[min_i] = 1;

        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], h[min_i][j]);
        }
    }

}

int main() {
    cin >> n >> m;

    memset(h, 0x3f, sizeof h);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue;
        h[a][b] = h[b][a] = min(h[a][b], c);
    }

    prim();

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == 0x3f3f3f3f) {
            cout << "impossible";
            return 0;
        }
        sum += dist[i];
    }
    cout << sum;
}


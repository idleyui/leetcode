// https://www.acwing.com/problem/content/852/
#include<cstring>
#include<iostream>
#include<queue>
#include <climits>

using namespace std;


const int N = 510, M = 10010;

int n, m, k;
int e[M][3], dist[N], last[N];

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; ++i) {
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m; ++j) {
            int a = e[j][0], b = e[j][1], w = e[j][2];
            dist[b] = min(dist[b], last[a] + w);
        }
    }
    return (dist[n] > 0x3f3f3f3f / 2) ? -1 : dist[n];
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
    }
    int t = bellman_ford();
    if (t == -1) cout << "impossible";
    else cout << t;
}


// https://www.acwing.com/problem/content/850/
#include<cstring>
#include<iostream>
#include<queue>
#include <climits>

using namespace std;

const int N = 100010, M = N * 2;

int n, m;
int h[N], e[M], ne[M], d[M], idx;
int dist[N], visit[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], d[idx] = c, h[a] = idx++;
}

int dijkstra() {
    for (int i = 0; i <= n; i++) dist[i] = INT_MAX;
    dist[1] = 0;
    while (true) {
        int min_i = 0;
        for (int i = 1; i <= n; i++) {
            if (!visit[i] && dist[i] < dist[min_i]) min_i = i;
        }
        if (!min_i) break;
        visit[min_i] = 1;
        for (int i = h[min_i]; i != -1; i = ne[i]) {
            int j = e[i];
            dist[j] = min(dist[min_i] + d[i], dist[j]);
        }
    }
    return dist[n] == INT_MAX ? -1 : dist[n];
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra();
}


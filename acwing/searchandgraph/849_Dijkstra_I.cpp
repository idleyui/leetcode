// https://www.acwing.com/problem/content/851/
#include<cstring>
#include<iostream>
#include<queue>
#include <climits>

using namespace std;

const int N = 510, MAX = 10010;

int n, m;
int h[N][N];
int dist[N], visit[N];

int dijkstra() {
    memset(dist, MAX, sizeof dist);
    dist[1] = 0;

    while (true) {
        int min_i = 0;
        for (int i = 1; i <= n; i++) {
            if (!visit[i] && dist[i] < dist[min_i]) min_i = i;
        }
        if (!min_i) break;
        visit[min_i] = 1;

        for (int i = 1; i <= n; ++i) {
            dist[i] = min(dist[min_i] + h[min_i][i], dist[i]);
        }
    }
    return dist[n] == MAX ? -1 : dist[n];
}

int main() {
    cin >> n >> m;
    memset(h, MAX, sizeof h);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == y) continue;
        h[x][y] = min(h[x][y], z);
    }
    cout << dijkstra();
}


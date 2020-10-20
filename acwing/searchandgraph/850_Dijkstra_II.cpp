// https://www.acwing.com/problem/content/852/
#include<cstring>
#include<iostream>
#include<queue>
#include <climits>

using namespace std;


typedef pair<int, int> PII;
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

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        int min_i = t.second, min_dist = t.first;
        if (visit[min_i]) continue;
        visit[min_i] = 1;
        for (int i = h[min_i]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > min_dist + d[i]) {
                dist[j] = min_dist + d[i];
                heap.push({dist[j], j});
            }
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


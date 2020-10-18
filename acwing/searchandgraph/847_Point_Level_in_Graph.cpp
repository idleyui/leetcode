// https://www.acwing.com/problem/content/849/
#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

const int N = 100010, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
int dist[N];
queue<int> q;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int u) {
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        for (int i = h[front]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] == -1) {
                dist[j] = dist[front] + 1;
                q.push(j);
//                if (j == n) { return dist[j]; }
            }
        }
    }
    return dist[n];
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    cout << bfs(1);
}


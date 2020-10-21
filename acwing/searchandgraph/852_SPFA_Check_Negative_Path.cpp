// https://www.acwing.com/problem/content/852/
#include<cstring>
#include<iostream>
#include<queue>
#include <climits>

using namespace std;


const int N = 100010, M = 100010;
int h[N], e[M], ne[M], d[M], idx = 0;
int dist[N], st[N], cnt[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], d[idx] = c, h[a] = idx++;
}


bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    st[1] = 1;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        st[front] = 0;
        for (int i = h[front]; i != -1; i = ne[i]) {
            int j = e[i];
            // care about j or i (d[i] / dist[j])
            if (dist[j] > dist[front] + d[i]) {
                dist[j] = dist[front] + d[i];
                cnt[j]++;
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if(spfa()) cout << "Yes";
    else cout << "No";
}


// https://www.acwing.com/problem/content/850/
#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

const int N = 100010, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
int degree[N];
queue<int> q;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    degree[b]++;
}

vector<int> top() {
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        auto front = q.front();
        ans.push_back(front);
        q.pop();
        for (int i = h[front]; i != -1; i = ne[i]) {
            int j = e[i];
            degree[j]--;
            if (degree[j] == 0) {
                q.push(j);
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    auto ans = top();
    if (ans[0] == -1 || ans.size() < n) cout << -1;
    else {
        for (int i: ans) cout << i << ' ';
    }
}


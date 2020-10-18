// https://www.acwing.com/problem/content/848/
#include<cstring>
#include<iostream>
//#include<algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N;
int n;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    st[u] = true;

    int MAX = 0, SUM = 1;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int val = dfs(j);
            MAX = max(MAX, val);
            SUM += val;
        }
    }
    MAX = max(MAX, n - SUM);
    ans = min(MAX, ans);
    return SUM;
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1);
    cout << ans << endl;
}


// https://www.acwing.com/problem/content/861/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;


const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

int add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int t, int c) {
    color[t] = c;
    for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!color[j]){

            if (!dfs(j, 3 - c))
                return false;
        }
        else if (color[j] == c) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }


    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                cout << "No";
                return 0;
            }
        }
    }
    puts("Yes");
}


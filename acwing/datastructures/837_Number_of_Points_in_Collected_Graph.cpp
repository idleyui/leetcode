// https://www.acwing.com/problem/content/839/
#include<iostream>

using namespace std;

const int N = 100010;

int parent[N], cnt[N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) { parent[i] = i; cnt[i] = 1;}

    string op;
    int a, b;
    while (m--) {
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            int root_a = find(a);
            int root_b = find(b);
            if (root_a != root_b) {
                cnt[root_b] += cnt[root_a];
                cnt[root_a] = 0;
                parent[root_a] = root_b;
            }
        } else if (op == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if (op == "Q2") {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
}

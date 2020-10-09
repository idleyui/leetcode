// https://www.acwing.com/problem/content/838/
#include<iostream>

using namespace std;

const int N = 100010;

int parent[N];

int check(int num) {
    int i = num;
    while (parent[i] != i) { i = parent[i]; }
    while (parent[num] != num) {
        num = parent[num];
        parent[num] = i;
    }
    return i;
}

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) { parent[i] = i; }

    char op;
    int a, b;
    while (m--) {
        cin >> op >> a >> b;
        if (op == 'M') {
            parent[find(a)] = find(b);
        } else if (op == 'Q') {
            if (check(a) == check(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

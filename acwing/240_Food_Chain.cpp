// https://www.acwing.com/problem/content/242/
#include<iostream>

using namespace std;

const int N = 50010;

// 1. use d[x] represent distance between x and parent[x]
int p[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
// 2. update d[x]
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        d[i] = 0;
    }

    int op, x, y, cnt = 0;
    while (k--) {
        cin >> op >> x >> y;
        if (x > n || y > n) {
            cnt++;
            continue;
        }

        int px = find(x), py = find(y);
        if (op == 1) {
            if (px == py) {
// 3. handle negative idx
//                -1 % 3 != 2 % 3
//                (-1 - 2) % 3 == 0
//                if (d[x] % 3 != d[y] % 3) {
                if ((d[x] - d[y]) % 3)
                    cnt++;
            }
        } else {
            p[px] = py;
            d[px] = d[y] - d[x];
        }
    } else {
        if (px == py) {
            if ((d[x] - d[y] - 1) % 3) cnt++;
        } else {
            p[px] = py;
            d[px] = d[y] + 1 - d[x];
        }
    }
}

cout <<
cnt;
}

// https://www.acwing.com/problem/content/843/
#include<iostream>
#include<vector>

using namespace std;
typedef unsigned long long ull;

const int N = 100010, P = 131;

int n, m;
string str(N, 0);
ull h[N], p[N];


ull hashcode(int r) {
    ull code = 0;
    for (int i = 0; i <= r; i++) {
        char c = str[i];
        code = code * P + (c - 'a');
    }
    return code;
}

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

ull power(ull base, ull n) {
    return base;
}

int main() {
    cin >> n >> m;
    cin >> str[1];
    str = ' ' + str;

    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }

    int l1, r1, l2, r2;
    while (m--) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}


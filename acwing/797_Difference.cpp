// https://www.acwing.com/problem/content/799/
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int A[N], B[N];

void insert(int l, int r, int c) {
    B[l] += c;
    B[r+1] -= c;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        insert(i, i, A[i]);
    }

    int l, r, c;
    while(m--) {
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++) {
        B[i] += B[i-1];
        cout << B[i] << ' ';
    }
}
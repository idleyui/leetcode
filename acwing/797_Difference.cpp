// https://www.acwing.com/problem/content/799/
#include <vector>
#include <iostream>

using namespace std;

void insert(vector<int> &B, int l, int r, int c) {
    B[l] += c;
    B[r + 1] -= c;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 2, 0), B(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        insert(B, i, i, A[i]);
    }

    int l, r, c;
    while (m--) {
        cin >> l >> r >> c;
        insert(B, l, r, c);
    }

    for (int i = 1; i <= n; i++) {
        B[i] += B[i - 1];
        cout << B[i] << ' ';
    }
}

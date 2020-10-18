// https://www.acwing.com/problem/content/145/
#include<iostream>
#include<vector>

using namespace std;

const int N = 100010;

int son[N*31][2], idx;

void insert(int num) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = (num >> i) & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int maxor(int num) {
    int p = 0;
    int val = 0;
    for (int i = 30; i >= 0; i--) {
        int u = !((num >> i) & 1);
        if (!son[p][u]) u = !u;
        val <<= 1;
        val += u;
        p = son[p][u];
    }
    return val ^ num;
}

int main() {
    int n;
    vector<int> A(n, 0);
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> A[i]; }

    for (int i = 0; i < n; ++i) {
        insert(A[i]);
    }

    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        max_val = max(max_val, maxor(A[i]));
    }
    cout << max_val;
}

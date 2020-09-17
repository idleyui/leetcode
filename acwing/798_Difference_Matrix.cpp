// https://www.acwing.com/problem/content/800/
#include <vector>
#include <iostream>

using namespace std;

void insert(vector<vector<int>> &B, int x1, int y1, int x2, int y2, int c) {
    B[x1][y1] += c;
    B[x2 + 1][y1] -= c;
    B[x1][y2 + 1] -= c;
    B[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> A(n + 2, vector<int>(m + 2, 0)),
            B(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            cin >> A[i][j];
            insert(B, i, j, i, j, A[i][j]);
        }
    }

    int x1, y1, x2, y2, c;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(B, x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            B[i][j] = B[i][j] + B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }
}

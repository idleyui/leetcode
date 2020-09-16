// https://www.acwing.com/problem/content/798/
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> build_sub_sum(vector<vector<int>> &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> sub_sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sub_sum[i][j] = sub_sum[i - 1][j] + sub_sum[i][j - 1] - sub_sum[i - 1][j - 1] + A[i - 1][j - 1];
        }
    }
    return sub_sum;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> A(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    auto sub_sum = build_sub_sum(A);
    int x1, y1, x2, y2;
    for (int i = 0; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sub_sum[x2][y2] - sub_sum[x1 - 1][y2] - sub_sum[x2][y1 - 1] + sub_sum[x1 - 1][y1 - 1] << endl;
    }
}

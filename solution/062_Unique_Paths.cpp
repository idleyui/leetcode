#include "alg.h"

vector<vector<int>> visited = {};

int recur(int m, int n, int x, int y) {
    if (visited[x][y] != 0) return visited[x][y];
    int right = 0, down = 0;
    if (x < m - 1) {
        right = recur(m, n, x + 1, y);
    }
    if (y < n - 1) {
        down = recur(m, n, x, y + 1);
    }
    visited[x][y] = right + down;
    return right + down;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> v(m, vector<int>(n, 0));
    visited = v;
    visited[m - 1][n - 1] = 1;
    return recur(m, n, 0, 0);
}

int main() {
    cout << uniquePaths(1, 1)<< endl;
    cout << uniquePaths(1, 10)<< endl;
    cout << uniquePaths(3, 2)<< endl;
    cout << uniquePaths(7, 3)<< endl;
    cout << uniquePaths(23, 12)<< endl;
}
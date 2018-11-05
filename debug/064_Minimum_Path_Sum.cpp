#include "alg.h"

int minPathSum(vector<vector<int>> &grid) {
    if (grid.size() == 0) return 0;
    int m = grid.size(), n = grid[0].size();
    int sum[m][n] = {};
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1) {
                sum[i][j] = grid[i][j];
            } else if (i == m - 1) {
                sum[i][j] = grid[i][j] + sum[i][j + 1];
            } else if (j == n - 1) {
                sum[i][j] = grid[i][j] + sum[i + 1][j];
            } else {
                sum[i][j] = grid[i][j] + min(sum[i + 1][j], sum[i][j + 1]);
            }
        }
    }
    return sum[0][0];
}

int main() {

}
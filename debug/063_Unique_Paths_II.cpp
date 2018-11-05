#include "alg.h"

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.size() == 0) return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int path[m][n] = {0};
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (obstacleGrid[i][j] == 1) {
                path[i][j] = 0;
            } else if (i == m - 1 && j == n - 1) {
                path[i][j] = 1;
            } else if (i == m - 1) {
                path[i][j] = path[i][j + 1];
            } else if (j == n - 1) {
                path[i][j] = path[i + 1][j];
            } else {
                path[i][j] = path[i + 1][j] + path[i][j + 1];
            }
        }
    }
    return path[0][0];
}

int main() {

}
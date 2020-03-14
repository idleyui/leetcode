#include "alg.h"

int islandPerimeter(vector<vector<int>> &grid) {
    int perimeter = 0, n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) continue;
            if (j == 0 || !grid[i][j - 1]) perimeter++;
            if (j == m - 1 || !grid[i][j + 1]) perimeter++;
            if (i == 0 || !grid[i - 1][j]) perimeter++;
            if (i == n - 1 || !grid[i + 1][j]) perimeter++;
        }
    }
    return perimeter;
}

int main() {

}
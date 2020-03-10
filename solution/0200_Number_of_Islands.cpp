#include "alg.h"

void expand(vector<vector<char>> &grid, vector<vector<int>> &island, int i, int j, int idx) {
    if (island[i][j] == idx) return;
    island[i][j] = idx;
    if (i > 0 && grid[i - 1][j] == '1') expand(grid, island, i - 1, j, idx);
    if (j > 0 && grid[i][j - 1] == '1') expand(grid, island, i, j - 1, idx);
    if (i < grid.size() - 1 && grid[i + 1][j] == '1') expand(grid, island, i + 1, j, idx);
    if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') expand(grid, island, i, j + 1, idx);
}

int numIslands(vector<vector<char>> &grid) {
    vector<vector<int>> island(grid.size(), vector<int>(grid[0].size(), 0));
    int idx = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '0' || island[i][j] > 0)continue;
            expand(grid, island, i, j, ++idx);
        }
    }
    return idx;
}

int main() {

}
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        vector<int> maxInRow(grid.size());
        vector<int> maxInColumn(grid[0].size());
        int areacount = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int value = grid[i][j];
                maxInRow[i] = value > maxInRow[i] ? value : maxInRow[i];
                maxInColumn[j] = value > maxInColumn[j] ? value : maxInColumn[j];
                if (value > 0)areacount++;
            }
        }

        return accumulate(maxInRow.begin(), maxInRow.end(), 0) +
               accumulate(maxInColumn.begin(), maxInColumn.end(), 0) +
               areacount;
    }
};
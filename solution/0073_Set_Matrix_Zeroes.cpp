#include "alg.h"

void setZeroes_O_m_plus_n(vector<vector<int>> &matrix) {
    unordered_set<int> row;
    unordered_set<int> column;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                row.insert(i);
                column.insert(j);
            }
        }
    }

    for (int i: row)
        for (int &num: matrix[i])
            num = 0;

    for (int i: column)
        for (int row = 0; row < matrix.size(); row++)
            matrix[row][i] = 0;
}

//https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution
void setZeroes(vector<vector<int>> &matrix) {
    int col0 = 1, rows = matrix.size(), columns = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < columns; j++) {
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
        }
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = columns - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
        if (col0 == 0) matrix[i][0] = 0;
    }
}


int main() {

}
#include "alg.h"

vector<vector<int>> dp;

NumMatrix(vector<vector<int>>
matrix) {
if (matrix.

empty()

) return;
vector<vector<int>> d(matrix.size(), vector < int > (matrix[0].size() + 1, 0));
for (
int i = 0;
i<matrix.

size();

i++){
for (
int j = 1;
j <= matrix[0].

size();

j++){
d[i][j] = d[i][j-1]+matrix[i][j-1];
}
}
dp = d;
}

int sumRegion(int row1, int col1, int row2, int col2) {
    if (row1 > row2 || col1 > col2 || row1 < 0 || row2 > dp.size() || col1 < 0 || col2 > dp[0].size() - 1) return 0;
    int sum = 0;
    for (int row = row1; row <= row2; row++) {
        sum += (dp[row][col2 + 1] - dp[row][col1]);
    }
    return sum;
}

int main() {

}
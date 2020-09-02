#include "alg.h"

vector <vector<int>> generateMatrix(int n) {
    if (n == 1) return {{1}};
    vector <vector<int>> matrix(n, vector<int>(n, 0));
    int i = 0, j = 0, cur = 1;
    while (true) {
        for (; j < n && matrix[i][j] == 0; j++) matrix[i][j] = cur++;
        if (matrix[++i][--j] != 0) break;
        for (; i < n && matrix[i][j] == 0; i++) matrix[i][j] = cur++;
        if (matrix[--i][--j] != 0) break;
        for (; j >= 0 && matrix[i][j] == 0; j--) matrix[i][j] = cur++;
        if (matrix[--i][++j] != 0) break;
        for (; i >= 0 && matrix[i][j] == 0; i--) matrix[i][j] = cur++;
        if (matrix[++i][++j] != 0) break;
    }
    return matrix;
}

int main() {

}
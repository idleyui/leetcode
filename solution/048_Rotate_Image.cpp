#include "alg.h"


void rotate(vector<vector<int>> &matrix, int i1, int i2) {
    for (int i = 0; i < i2 - i1; i++) {
        // cout << i1 << i << i2;
        swap(matrix[i1][i1 + i], matrix[i2 - i][i1]);
        swap(matrix[i2 - i][i1], matrix[i2][i2 - i]);
        swap(matrix[i2][i2 - i], matrix[i1 + i][i2]);
    }
}

void rotate(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size() / 2; i++) {
        rotate(matrix, i, matrix.size() - i - 1);
    }
}

int main() {

}
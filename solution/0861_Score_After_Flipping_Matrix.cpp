#include "alg.h"


int matrixScore(vector<vector<int>> A) {
    bool change = false;
    int m = A.size(), n = A[0].size();
    auto rrow = [&A, &change](int row) -> void {
        for (int &i : A[row]) {
            i = i == 0 ? 1 : 0;
        }
        change = true;
    };
    auto rcolumn = [&A, &change](int column) -> void {
        for (auto &row : A) {
            row[column] = row[column] == 0 ? 1 : 0;
        }
        change = true;
    };
    do {
        change = false;
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0) {
                rrow(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            int one = 0;
            for (auto &row: A) { one += row[i]; }
            if (one * 2 < m)rcolumn(i);
        }
    } while (!change);

    int rt = 0;
    for (auto &row:A) {
        int val = 0;
        for (int i: row) {
            val <<= 1;
            if (i == 1)val |= 1;
        }
        rt += val;
    }
    return rt;
}

int main() {
    cout << matrixScore({{0, 0, 1, 1},
                         {0, 0, 1, 1},
                         {0, 0, 1, 1},}) << endl;
    cout << matrixScore({{0, 0, 1, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 0},}) << endl;
    cout << matrixScore({{0, 0, 0, 0},
                         {1, 0, 0, 0},
                         {1, 1, 0, 0},}) << endl;
}
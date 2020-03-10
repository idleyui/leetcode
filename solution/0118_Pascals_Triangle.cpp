#include "alg.h"

vector<vector<int>> generate(int numRows) {
    if (numRows == 0) return {};
    vector<vector<int>> result = {};
    result.reserve(numRows);
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
            row[j] = result[i - 1][j - 1] + result[i - 1][j];
        result.push_back(row);
    }
    return result;
}

int main() {

}
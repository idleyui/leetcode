#include "alg.h"

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) return {};
    bool flat = true;
    int flat_plus = 1;
    int down_plus = 1;
    int left = 0, up = 0, right = matrix[0].size() - 1, down = matrix.size() - 1;
    vector<int> result;
    int N = matrix.size() * matrix[0].size();
    result.reserve(N);
    int i = left, j = up;
    while (result.size() < N) {
        result.push_back(matrix[i][j]);
        if (flat) {
            if (flat_plus == 1 && j != right ||
                flat_plus == -1 && j != left) {
                j += flat_plus;
            } else {
                if (down_plus > 0) {
                    up++;
                } else {
                    down--;
                }

                flat_plus = -flat_plus;
                i += down_plus;
                flat = false;
            }
        } else {
            if (down_plus == 1 && i != down ||
                down_plus == -1 && i != up) {
                i += down_plus;
            } else {
                if (flat_plus > 0) {
                    left++;
                } else {
                    right--;
                }

                down_plus = -down_plus;
                j += flat_plus;
                flat = true;
            }
        }
        // cout << up << down << left << right << endl;
    }
    return result;

}

// https://leetcode.com/problems/spiral-matrix/discuss/20719/C%2B%2B-spiral-traverse
vector<int> spiralOrder1(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = m ? matrix[0].size() : 0, u = 0, d = m - 1, l = 0, r = n - 1;
    vector<int> result;
    result.reserve(m * n);
    while (result.size() < m * n) {
        for (int c = l; c <= r; c++) result.push_back(matrix[u][c]);
        if (++u > d) break;
        for (int row = u; row <= d; row++) result.push_back(matrix[row][r]);
        if (--r < l)break;
        for (int c = r; c >= l; c--) result.push_back(matrix[d][c]);
        if (--d < u)break;
        for (int row = d; row >= u; row--) result.push_back(matrix[row][l]);
        if (++l > r)break;
    }
    return result;
}

int main() {

}
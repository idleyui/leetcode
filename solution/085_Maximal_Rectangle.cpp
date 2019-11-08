#include "alg.h"

int largestRectangleArea(vector<int> &height) {
    int ret = 0;
    height.push_back(0);
    vector<int> index;

    for (int i = 0; i < height.size(); ++i) {
        while (index.size() > 0 && height[index.back()] >= height[i]) {
            int h = height[index.back()];
            index.pop_back();

            int sidx = index.size() > 0 ? index.back() : -1;
            if (h * (i - sidx - 1) > ret) ret = h * (i - sidx - 1);
        }
        index.push_back(i);
    }
    return ret;
}

int maximalRectangle(vector<vector<char>> &matrix) {
    int n = matrix.size(), m = n > 0 ? matrix[0].size() : 0, max_val = 0;
    vector<int> height(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '0') height[j] = 0;
            else height[j] += 1;
        }
        max_val = max(max_val, largestRectangleArea(height));
    }
    return max_val;
}

int main() {

}
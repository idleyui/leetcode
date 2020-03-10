#include "alg.h"

// Solution 1: naive swap
// https://leetcode.com/problems/rotate-image/discuss/19002/4ms-few-lines-C%2B%2B-code-Rotate-Image-90-degree-for-O(1)-space
void rotate1(vector<vector<int>> &matrix) {
    int left = 0, right = matrix.size() - 1;
    while (left < right) {
        for (int i = 0; i < right - left; i++) {
            swap(matrix[left][left + i], matrix[left + i][right]);
            swap(matrix[left][left + i], matrix[right][right - i]);
            swap(matrix[left][left + i], matrix[right - i][left]);
        }
        left++;
        right--;
    }
}

// Solution 2: reverse and swap
// https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
void rotate2(vector<vector<int>> &matrix){
    reverse(matrix.begin(), matrix.end());
    for(int i = 0; i < matrix.size(); i++){
        for(int j = i+1; j < matrix[0].size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {

}
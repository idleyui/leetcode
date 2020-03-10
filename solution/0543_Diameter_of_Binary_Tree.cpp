#include "alg.h"

vector<int> rec(TreeNode *root) {
    if (!root) return {0, 0};
    auto left = rec(root->left);
    auto right = rec(root->right);
    int left_single = left[0], left_double = left[1];
    int right_single = right[0], right_double = right[1];
    int new_sum = left_single + right_single;
    new_sum = max(new_sum, left_double);
    new_sum = max(new_sum, right_double);
    return {max(left_single, right_single) + 1, new_sum};
}

int diameterOfBinaryTree(TreeNode *root) {
    auto v = rec(root);
    return max(v[1], v[0] - 1);
}

int main() {

}
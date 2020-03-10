#include "alg.h"


int max_val = INT_MIN;

int maxP(TreeNode *root) {
    if (!root) return 0;
    int left = maxP(root->left);
    int right = maxP(root->right);
    int sum = (left > 0 ? left : 0) + (right > 0 ? right : 0) + root->val;
    int max_single = max(left, right);
    max_val = max(max_val, max_single);
    max_val = max(max_val, sum);
    return max_single > 0 ? max_single + root->val : root->val;
}

int maxPathSum(TreeNode *root) {
    max_val = INT_MIN;
    maxP(root);
    return max_val;
}

int main() {
}
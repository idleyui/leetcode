#include "alg.h"

int MAX = INT_MIN;

// calculate max sum include root
int dfs(TreeNode *root) {
    if (!root) return 0;
    int l = max(0, dfs(root->left)), r = max(0, dfs(root->right));
    int sum = l + r + root->val;
    MAX = max(sum, MAX);
    // keep root->val
    return max(l, r) + root->val;
}

int maxPathSum(TreeNode *root) {
    dfs(root);
    return MAX;
}

int main() {
}
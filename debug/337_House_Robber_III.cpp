#include "alg.h"

int rob(TreeNode *root, map<TreeNode *, int> &dp) {
    if (dp.count(root)) return dp[root];
    TreeNode *left = root->left, *right = root->right;
    int withroot = root->val + (left ? (rob(left->left, dp) + rob(left->right, dp)) : 0) +
                   (right ? (rob(right->left, dp) + rob(right->right, dp)) : 0);
    int val = max(rob(root->left, dp) + rob(root->right, dp), withroot);
    dp[root] = val;
    return val;
}

int rob(TreeNode *root) {
    map<TreeNode *, int> dp = {};
    dp[NULL] = 0;
    return rob(root, dp);
}


int main() {
    TreeNode *node = new TreeNode(3);
    TreeNode *node1 = node;
    node1->val = 2;
    cout << rob(node);
}
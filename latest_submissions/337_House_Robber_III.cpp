/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        map<TreeNode*, int> dp = {};
        dp[NULL] = 0;
        return rob(root, dp);
    }
    
    int rob(TreeNode* root, map<TreeNode*, int> &dp){
        if (dp.count(root)) return dp[root];
        TreeNode* left = root->left, *right = root->right;
        int withroot = (root->val) + (left?(rob(left->left, dp)+rob(left->right, dp)):0)
                                + (right?(rob(right->left, dp) + rob(right->right, dp)):0);
        int val = max(rob(root->left, dp) + rob(root->right, dp), withroot);
        dp[root] = val;
        return val;
    }
};
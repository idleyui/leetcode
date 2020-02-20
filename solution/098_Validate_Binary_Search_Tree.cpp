#include "alg.h"

// Solution 1: Use long to set boundary value
bool isValidBST1(TreeNode *root, long low, long high) {
    if (!root)return true;
    if (root->val <= low || root->val >= high) return false;
    return isValidBST1(root->left, low, root->val) && isValidBST1(root->right, root->val, high);
}

bool isValidBST1(TreeNode *root) {
    return isValidBST1(root, (long) INT_MIN - 1, (long) INT_MAX + 1);
}

// Solution 2: use Node to set boundary Node
// https://leetcode.com/problems/validate-binary-search-tree/discuss/32141/C%2B%2B-simple-recursive-solution
bool isValidBST2(TreeNode *root, TreeNode *min, TreeNode *max) {
    if (!root) return true;
    if ((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
    return isValidBST2(root->left, min, root) && isValidBST2(root->right, root, max);
}

bool isValidBST2(TreeNode *root) {
    return isValidBST2(root, nullptr, nullptr);
}

// Solution 3: iterative inorder traversal (idea from question 94)
// set pre as the left mast Node, the next right or next in stack less than this Node
// https://leetcode.com/problems/validate-binary-search-tree/discuss/32112/Learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-(Java-Solution)
bool isValidBST3(TreeNode *root) {
    TreeNode *pre = nullptr;
    stack<TreeNode *> todo;
    while (root || !todo.empty()) {
        while (root) {
            todo.push(root);
            root = root->left;
        }
        root = todo.top();
        todo.pop();
        if (pre && root->val <= pre->val) return false;
        pre = root;
        root = root->right;
    }
    return true;
}

int main() {
    cout << isValidBST1(mk_tree({INT_MAX}));
    cout << isValidBST1(mk_tree({1, 1}));
    cout << isValidBST1(mk_tree({0, NULL, -1}));
    cout << isValidBST1(mk_tree({2, 1, 3}));
    cout << isValidBST1(mk_tree({5, 1, 4, NULL, NULL, 3, 6}));
}
#include "alg.h"

TreeNode *first = nullptr, *second = nullptr, *pre = new TreeNode(INT_MIN);

// https://leetcode.com/problems/recover-binary-search-tree/discuss/32580/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explaination
void inorder(TreeNode *root) {
    if (!root) return;
    inorder(root->left);
    if (!first && pre->val > root->val) { first = pre; }
    if (first && pre->val > root->val) { second = root; }
    pre = root;
    inorder(root->right);
}

void recoverTree(TreeNode *root) {
    inorder(root);
    swap(first->val, second->val);
}

int main() {
    TreeNode *one = new TreeNode(1);
    TreeNode *two = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    one->left = three;
    three->right = two;
    recoverTree(one);
    cout << first->val;
}
#include "alg.h"

bool isValidBST(TreeNode *root, long low, long high) {
    if (!root)return true;
    if (root->val <= low || root->val >= high) return false;
    return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
}

bool isValidBST(TreeNode *root) {
    return isValidBST(root, (long) INT_MIN - 1, (long) INT_MAX + 1);
}

int main() {
    cout << isValidBST(mk_tree({INT_MAX}));
    cout << isValidBST(mk_tree({1, 1}));
    cout << isValidBST(mk_tree({0, NULL, -1}));
    cout << isValidBST(mk_tree({2, 1, 3}));
    cout << isValidBST(mk_tree({5, 1, 4, NULL, NULL, 3, 6}));
}
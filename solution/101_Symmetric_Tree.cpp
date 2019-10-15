#include "alg.h"

bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (!left && right || left && !right) return false;
    if (!left && !right) return true;
    return left->val == right->val && isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
}

bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
}

int main() {

}
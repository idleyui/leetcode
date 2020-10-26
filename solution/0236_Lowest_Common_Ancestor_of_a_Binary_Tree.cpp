#include "alg.h"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return nullptr;
    if (root == p || root == q) return root;
    auto l = lowestCommonAncestor(root->left, p, q);
    auto r = lowestCommonAncestor(root->right, p, q);
    if (l && r) return root;
    return l ? l : r;
}

int main() {

}
#include "alg.h"

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2) return nullptr;
    int sum = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
    TreeNode *n = new TreeNode(sum);
    n->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
    n->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
    return n;
}

TreeNode *mergeTrees_2(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2) return nullptr;
    if (!t1 || !t2) return t1 ? t1 : t2;
    TreeNode *root = new TreeNode(t1->val + t2->val);
    root->left = mergeTrees(t1->left, t2->left);
    root->right = mergeTrees(t1->right, t2->right);
    return root;
}

int main() {

}
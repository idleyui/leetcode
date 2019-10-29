#include "alg.h"


pair<TreeNode *, int> rec(TreeNode *root, int val1, int val2) {
    if (!root) return {nullptr, 0};

    pair<TreeNode *, int> pair1 = rec(root->left, val1, val2);
    if (pair1.second == 2) return pair1;
    pair<TreeNode *, int> pair2 = rec(root->right, val1, val2);
    if (pair2.second == 2) return pair2;
    if (pair1.second + pair2.second == 2) return {root, 2};

    if (root->val == val1 || root->val == val2) return {root, pair1.second + pair2.second + 1};
    else return {root, pair1.second + pair2.second};
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return rec(root, p->val, q->val).first;
}

int main() {

}
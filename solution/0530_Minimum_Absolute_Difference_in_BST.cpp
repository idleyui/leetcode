#include "alg.h"

void inorder(TreeNode *root, TreeNode *&last, int &MIN) {
    if (!root) return;
    inorder(root->left, last, MIN);
    if (!last) last = root;
    else MIN = min(MIN, abs(root->val - last->val));
    last = root;
    inorder(root->right, last, MIN);
}

int getMinimumDifference(TreeNode *root) {
    int MIN = INT_MAX;
    TreeNode *last = nullptr;
    inorder(root, last, MIN);
    return MIN;
}

int main() {

}
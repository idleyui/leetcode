#include "alg.h"

void traversal(TreeNode *root, int &sum) {
    if (!root) return;
    traversal(root->right, sum);
    sum += root->val;
    root->val = sum;
    traversal(root->left, sum);
}

TreeNode *convertBST(TreeNode *root) {
    int sum = 0;
    traversal(root, sum);
    return root;
}

int main() {

}
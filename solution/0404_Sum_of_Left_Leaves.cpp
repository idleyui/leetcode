#include "alg.h"

int sumOfLeftLeaves(TreeNode *root, bool left = false) {
    if (!root) return 0;
    if (!root->left && !root->right && left) return root->val;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int main() {

}
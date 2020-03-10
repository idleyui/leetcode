#include "alg.h"

// todo discuss
int minDepth(TreeNode *root) {
    if (!root) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (!left && !right) return 1;
    if (left && right) return min(left, right) + 1;
    else return max(left, right) + 1;
}

int main() {

}
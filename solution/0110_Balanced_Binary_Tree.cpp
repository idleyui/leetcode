#include "alg.h"

// bottom-up
int high(TreeNode *root) {
    if (!root) return 0;
    int h1 = high(root->left), h2 = high(root->right);
    if (h1 == -1 || h2 == -1) return -1;
    if (h1 < h2) swap(h1, h2);
    if (h1 - h2 > 1) return -1;
    return h1 + 1;
}

bool isBalanced(TreeNode *root) {
    int h = high(root);
    return h != -1;
}

int main() {

}
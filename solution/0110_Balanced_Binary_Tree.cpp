#include "alg.h"

// todo discuss
// balance, height
pair<int, int> isBalance(TreeNode *root) {
    if (!root) return {true, 0};
    auto p1 = isBalance(root->left);
    if (!p1.first) return {false, 0};
    auto p2 = isBalance(root->right);
    if (!p2.first) return {false, 0};
    if (p1.second > p2.second) swap(p1, p2);
    return {p2.second - p1.second <= 1, max(p1.second, p2.second) + 1};
}

bool isBalanced(TreeNode *root) {
    return isBalance(root).first;
}

int main() {

}
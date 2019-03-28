#include "alg.h"

vector<int> result;

void r(TreeNode *root) {
    if (!root) return;
    r(root->left);
    r(root->right);
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root) {
    r(root);
    return result;
}

vector<int> postorderTraversal1(TreeNode *root) {
}

int main() {
    print_container(postorderTraversal(mk_tree({1, 2, 3})));
}
#include "alg.h"

stack<TreeNode *> stk;


void flatten(TreeNode *root) {
    if (!root) return;
    if (root->right) stk.push(root->right);
    if (root->left) {
        root->right = root->left;
        root->left = nullptr;
    } else if (!stk.empty()) {
        root->right = stk.top();
        stk.pop();
    }
    flatten(root->right);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    flatten(root);
    print_tree(root);
}
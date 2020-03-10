#include "alg.h"

vector<int> result;

void r(TreeNode *root) {
    if (!root) return;
    result.push_back(root->val);
    r(root->left);
    r(root->right);
}

vector<int> preorderTraversal(TreeNode *root) {
    r(root);
    return result;
}

vector<int> preorderTraversal1(TreeNode *root) {
    vector<int> v;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
        auto top = s.top();
        s.pop();
        v.push_back(top->val);
        if (top->right) { s.push(top->right); }
        if (top->left) { s.push(top->left); }
    }
    return v;
}

int main() {
    auto tree = mk_tree({1, 2, 3, 4, 5});
    print_container(preorderTraversal1(tree));
}
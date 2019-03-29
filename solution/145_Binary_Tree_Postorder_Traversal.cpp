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
    if (!root) return {};
    vector<int> v;
    stack<TreeNode *> s;
    s.push(root);
    unordered_set<TreeNode *> visited;
    while (!s.empty()) {
        auto top = s.top();
        if (visited.count(top) || (!top->left && !top->right)) {
            s.pop();
            v.push_back(top->val);
        } else {
            if (top->right) { s.push(top->right); }
            if (top->left) { s.push(top->left); }
            visited.insert(top);
        }
    }
    return v;
}

int main() {
//    print_container(postorderTraversal(mk_tree({1, 2, 3})));
    print_container(postorderTraversal1(mk_tree({1, 2, 3, 4, 5, 6, 7,})));
}
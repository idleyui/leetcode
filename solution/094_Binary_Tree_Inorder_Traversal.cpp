#include "alg.h"

void inorderTravelsal(TreeNode *root, vector<int> &v) {
    if (!root) return;
    inorderTravelsal(root->left, v);
    v.push_back(root->val);
    inorderTravelsal(root->right, v);
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> v;
    inorderTravelsal(root, v);
    return v;
}

// with stack
vector<int> inorderTraversal2(TreeNode *root) {
    if (!root) return {};
    vector<int> result;
    stack<TreeNode *> nodes({root});
    while (!nodes.empty()) {
        auto top = nodes.top();
        if (top->left) {
            while (top->left) {
                nodes.push(top->left);
                top = top->left;
            }
        } else {
            result.push_back(top->val);
            nodes.pop();
            if (top->right)nodes.push(top->right);
        }
    }
    return result;
}

// morris traversal
vector<int> inorderTraversal3(TreeNode *root) {
    vector<int> rt;
    TreeNode *curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode *rightmost = curr->left;
            while (rightmost->right && rightmost->right != curr) rightmost = rightmost->right;

            if (!rightmost->right) {
                rightmost->right = curr;
                curr = curr->left;
            } else {
                rightmost->right = nullptr;

            }
        }
    }
}

int main() {

}
#include "alg.h"

vector<int> v;

void r(TreeNode *root) {
    if (!root) return;
    r(root->left);
    v.push_back(root->val);
    r(root->right);
}

vector<int> inorderTravelsal(TreeNode *root) {
    r(root);
    return v;
}


// with stack
vector<int> inorderTraversal2(TreeNode *root) {
    if (!root) return {};
    vector<int> result;
    unordered_set<TreeNode *> visited;
    stack<TreeNode *> nodes({root});

    while (!nodes.empty()) {
        auto top = nodes.top();
        if (!visited.count(top) && top->left) {
            visited.insert(top);
            nodes.push(top->left);
        } else {
            result.push_back(top->val);
            nodes.pop();
            if (top->right)nodes.push(top->right);
        }
    }
    return result;
}

// morris traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/148939/CPP-Morris-Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31232/Three-Methods-to-Solve-(C%2B%2B)
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
    auto root = mk_tree({1, 2, 3, 4, 5, 6, 7});
    print_tree(root);
}
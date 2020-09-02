#include "alg.h"

// Solution 1: recursion
void r(TreeNode *root, vector<int> &v) {
    if (!root) return;
    r(root->left, v);
    v.push_back(root->val);
    r(root->right, v);
}

vector<int> inorderTravelsal(TreeNode *root) {
    vector<int> v;
    r(root, v);
    return v;
}


// Solution 2: iterative with stack
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

// without visited set
// pop mid node before visit right
// https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31213/Iterative-solution-in-Java-simple-and-readable
// https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris
vector<int> inroderTraversal2_(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> stk;
    while (root || !stk.empty()) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
        auto top = stk.top();
        stk.pop();
        result.push_back(top->val);
        root = top->right;
    }
    return result;
}

// Solution 3: morris traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/148939/CPP-Morris-Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31232/Three-Methods-to-Solve-(C%2B%2B)
// https://zhuanlan.zhihu.com/p/102285533
vector<int> inorderTraversal3(TreeNode *root) {
    vector<int> result;
    int i = 0;
    while (root) {
        if (i++ > 20) break;
        cout << "rt" << root->val << endl;
        if (root->left) {
            TreeNode *cur = root->left;
            while (cur->right && cur->right != root) { cur = cur->right; }
            if (!cur->right) {
                cur->right = root;
                root = root->left;
            } else {
                cout << 'l' << root->val << endl;
                // cur->right = nullptr;
                result.push_back(root->val);
                root = root->right;
            }
        } else {
            cout << 'r' << root->val << endl;
            result.push_back(root->val);
            root = root->right;
        }
    }
    return result;
}

int main() {
    auto root = mk_tree({1, 2, 3, 4, 5});
    print_container(inorderTraversal3(root));
}
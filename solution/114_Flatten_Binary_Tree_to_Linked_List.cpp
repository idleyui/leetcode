#include "alg.h"


// Solution 1: use stack push right side
stack<TreeNode *> stk;

void flatten1_recursion(TreeNode *root) {
    if (!root) return;
    if (root->right) stk.push(root->right);
    if (root->left) {
        root->right = root->left;
        root->left = nullptr;
    } else if (!stk.empty()) {
        root->right = stk.top();
        stk.pop();
    }
    flatten1_recursion(root->right);
}

void flatten1_iterative(TreeNode *root) {
    if (!root) return;
    stack<TreeNode *> right;

    while (root->right || root->left || !right.empty()) {
        if (root->right) {
            right.push(root->right);
        }
        if (root->left) {
            root->right = root->left;
            root->left = nullptr;
        } else {
            root->right = right.top();
            right.pop();
        }
        root = root->right;
    }
}


// Solution 2: use first, last of left side to put into root and right side
vector<TreeNode *> f(TreeNode *root) {
    auto right = root->right;
    TreeNode *last = root;
    if (root->left) {
        auto left_pair = f(root->left);
        last->right = left_pair[0];
        last = left_pair[1];
        root->left = nullptr;
    }
    if (right) {
        auto right_pair = f(right);
        last->right = right_pair[0];
        last = right_pair[1];
    }
    return {root, last};
}

void flatten2(TreeNode *root) {
    if (!root) return;
    f(root);
}

// Solution 3: brilliant post order traversal
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
TreeNode *pre = nullptr;

void flatten3(TreeNode *root) {
    if (!root) return;
    flatten3(root->right);
    flatten3(root->left);
    root->right = pre;
    root->left = nullptr;
    pre = root;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    flatten1(root);
    print_tree(root);
}
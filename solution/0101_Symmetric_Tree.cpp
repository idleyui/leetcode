#include "alg.h"

// Solution 1: recursion
bool isSymmetric1(TreeNode *left, TreeNode *right) {
    if (!left && right || left && !right) return false;
    if (!left && !right) return true;
    return left->val == right->val && isSymmetric1(left->right, right->left) && isSymmetric1(left->left, right->right);
}

bool isSymmetric1(TreeNode *root) {
    if (!root) return true;
    return isSymmetric1(root->left, root->right);
}

// Solution 2: use two deque, level traversal
bool isSymmetric2(TreeNode *root) {
    if (!root) return true;
    deque<TreeNode *> level = {root->left, root->right};
    deque<TreeNode *> next_level;
    while (!level.empty()) {
        while (level.size() > 0) {
            auto left = level.front();
            auto right = level.back();
            level.pop_front();
            level.pop_back();
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            next_level.push_front(left->right);
            next_level.push_front(left->left);
            next_level.push_back(right->left);
            next_level.push_back(right->right);
        }
        level = next_level;
        next_level.clear();
    }
    return true;
}

// Solution 3: use stack, level traversal, put symmetric Node adjacent
// https://leetcode.com/problems/symmetric-tree/discuss/33054/Recursive-and-non-recursive-solutions-in-Java
bool isSymmetric3(TreeNode *root) {
    if (!root) return true;
    stack<TreeNode *> stk;
    stk.push(root->left);
    stk.push(root->right);
    while (!stk.empty()) {
        auto right = stk.top();
        stk.pop();
        auto left = stk.top();
        stk.pop();
        if (!left && !right) continue;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        stk.push(left->left);
        stk.push(right->right);
        stk.push(left->right);
        stk.push(right->left);
    }
    return true;
}

int main() {

}
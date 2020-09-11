// https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list/description
#include "alg.h"

pair<TreeNode *, TreeNode *> left_right(TreeNode *root) {
    if (!root) return {nullptr, nullptr};
    auto left = left_right(root->left);
    auto right = left_right(root->right);
    if (left.second) {
        left.second->right = root;
        root->left = left.second;
    }
    if (right.first) {
        right.first->left = root;
        root->right = right.first;
    }
    return {left.first ? left.first : root, right.second ? right.second : root};
}

// Solution 1: straight forward
TreeNode *treeToDoublyList_1(TreeNode *root) {
    auto p = left_right(root);
    p.first->left = p.second;
    p.second->right = p.first;
    return p.first;
}


void inorder(TreeNode *root, TreeNode *&head, TreeNode *&tail) {
    if (!root) return;
    inorder(root->left, head, tail);
    if (!head) {
        head = root;
        tail = root;
    } else {
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    inorder(root->right, head, tail);
}

// Solution 2: in order traversal
// https://www.cnblogs.com/grandyang/p/9615871.html
TreeNode *treeToDoublyList_2(TreeNode *root) {
    TreeNode *head = nullptr, *tail = nullptr;
    inorder(root, head, tail);
    head->left = tail;
    tail->right = head;
    return head;
}

int main() {

}
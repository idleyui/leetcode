#include "alg.h"

TreeNode *invertTree(TreeNode *root) {
    if (!root) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// with stack
TreeNode *invertTree_2(TreeNode *root) {
    deque<TreeNode *> q = {root};
    while (!q.empty()) {
        auto front = q.front();
        q.pop_front();
        if (!front) continue;
        swap(front->left, front->right);
        q.push_back(front->left);
        q.push_back(front->right);
    }
    return root;
}

int main() {

}
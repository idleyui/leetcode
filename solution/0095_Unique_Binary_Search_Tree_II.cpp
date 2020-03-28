#include "alg.h"

TreeNode *fill(TreeNode *base, int low) {
    if (!base) return nullptr;
    TreeNode *node = new TreeNode(base->val + low);
    node->left = fill(base->left, low);
    node->right = fill(base->right, low);
    return node;
}

vector<TreeNode *> generateTrees(int n) {
    if (n == 0) return {};
    vector<vector<TreeNode *>> n2trees(n + 1, vector<TreeNode *>());
    n2trees[0] = {nullptr};
    for (int i = 1; i <= n; i++) {
        for (int left = 0; left <= i - 1; left++) {
            for (auto left_root: n2trees[left]) {
                for (auto right_root: n2trees[i - left - 1]) {
                    TreeNode *midNode = new TreeNode(left + 1);
                    midNode->left = left_root;
                    midNode->right = fill(right_root, left + 1);
                    n2trees[i].push_back(midNode);
                }
            }
        }
    }
    return n2trees[n];
}

int main() {
}


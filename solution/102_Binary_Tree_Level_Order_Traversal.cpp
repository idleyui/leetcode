#include "alg.h"

vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    int size = 1;
    vector<int> v;
    while (!q.empty()) {
        auto node = q.front();
        v.push_back(node->val);
        q.pop();
        if (node->left)q.push(node->left);
        if (node->right)q.push(node->right);
        size -= 1;
        if (size == 0) {
            result.push_back(v);
            v = vector<int>();
            size = q.size();
        }
    }
    return result;
}

int main() {
//    auto rt = mk_tree({1, 2, 3, 4, 5, 6});
    auto rt = mk_tree({1});
    for (auto v: levelOrder(rt))
        print_container(v);
}
#include "alg.h"

// Solution 1: use deque size
vector<vector<int>> levelOrder1(TreeNode *root) {
    vector<vector<int>> result;
    deque<TreeNode *> level = {root};
    while (!level.empty()) {
        int n = level.size();
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            auto front = level.front();
            level.pop_front();
            if (!front) continue;

            cur.push_back(front->val);
            level.push_back(front->left);
            level.push_back(front->right);
        }
        if (!cur.empty()) result.push_back(cur);
    }
    return result;
}

// Solution 2: push NULL as mark
// https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33443/C%2B%2B-solution-using-only-one-queue-use-a-marker-NULL
vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> result;
    vector<int> cur;
    deque<TreeNode *> level = {root, nullptr};

    while (!level.empty()) {
        auto front = level.front();
        level.pop_front();
        if (!front) {
            result.push_back(cur);
            cur.clear();
            if (level.empty()) break;

            level.push_back(nullptr);
            continue;
        }

        cur.push_back(front->val);
        if (front->left) level.push_back(front->left);
        if (front->right) level.push_back(front->right);
    }
    return result;
}

vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        q.push(nullptr);
        vector<int> tmp;
        while (true) {
            auto front = q.front();
            q.pop();
            if (!front) break;
            tmp.push_back(front->val);
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        ans.push_back(tmp);
    }
    return ans;
}

// preorder traversal but get result
// https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33468/One-of-C%2B%2B-solutions-(preorder)

int main() {
//    auto rt = mk_tree({1, 2, 3, 4, 5, 6});
    auto rt = mk_tree({1});
    for (auto v: levelOrder1(rt))
        print_container(v);
}
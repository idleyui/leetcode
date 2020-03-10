#include "alg.h"

// todo discuss
// Solution 1
vector<vector<int>> levelOrderBottom_1(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> result;
    deque<TreeNode *> to_visit;
    to_visit.push_back(root);
    while (!to_visit.empty()) {
        to_visit.push_back(nullptr);
        vector<int> level;
        while (true) {
            auto front = to_visit.front();
            to_visit.pop_front();
            if (!front) break;
            level.push_back(front->val);
            if (front->left) to_visit.push_back(front->left);
            if (front->right) to_visit.push_back(front->right);
        }
        result.push_back(level);
    }
    reverse(result.begin(), result.end());
    return result;
}

// Solution 2
void dfs(vector<vector<int>> &result, TreeNode *root, int level) {
    if (!root) return;
    if (result.size() > level) result[level].push_back(root->val);
    else result.push_back({root->val});
    dfs(result, root->left, level + 1);
    dfs(result, root->right, level + 1);
}

vector<vector<int>> levelOrderBottom_2(TreeNode *root) {
    vector<vector<int>> result;
    dfs(result, root, 0);
    reverse(result.begin(), result.end());
    return result;
}

int main() {

}
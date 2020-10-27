#include "alg.h"

void dfs(TreeNode *root, int sum, vector<vector<int>> &paths, vector<int> &path) {
    sum -= root->val;
    path.push_back(root->val);
    if (!sum && !root->left && !root->right) paths.push_back(path);
    if (root->left) dfs(root->left, sum, paths, path);
    if (root->right) dfs(root->right, sum, paths, path);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    if (!root) return {};
    vector<vector<int>> paths;
    vector<int> path;
    dfs(root, sum, paths, path);
    return paths;
}

int main() {

}
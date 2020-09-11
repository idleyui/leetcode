#include "alg.h"

void pathSum(TreeNode *root, int sum, vector<vector<int>> &paths, vector<int> &path) {
    sum -= root->val;
    path.push_back(root->val);
    if (!sum && !root->left && !root->right) path.pop_back();
    if (root->left) pathSum(root->left, sum, paths, path, tmp);
    if (root->right) pathSum(root->right, sum, paths, path, tmp);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    if (!root) return {};
    vector<vector<int>> paths;
    vector<int> path;
    pathSum(root, sum, paths, path);
    return paths;
}

int main() {

}
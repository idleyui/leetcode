#include "alg.h"

// todo discuss
void dfs(vector<string> &ans, TreeNode *root, string tmp) {
    if (!root) return;
    tmp += to_string(root->val);
    if (!root->left && !root->right) {
        ans.push_back(tmp);
        return;
    }
    dfs(ans, root->left, tmp + "->");
    dfs(ans, root->right, tmp + "->");
}

vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    dfs(ans, root, "");
    return ans;
}

int main() {

}
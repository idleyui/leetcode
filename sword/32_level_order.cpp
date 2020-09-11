#include "alg.h"

vector<int> levelOrder(TreeNode *root) {
    if (!root) return {};
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        auto front = q.front();
        ans.push_back(front->val);
        q.pop();
        if (front->left) q.push(front->left);
        if (front->right)q.push(front->right);
    }
    return ans;
}

int main() {

}
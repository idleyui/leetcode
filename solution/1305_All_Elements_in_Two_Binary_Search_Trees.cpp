#include "alg.h"

void inorderTraversal(TreeNode *root, vector<int> &v) {
    if (!root) return;
    inorderTraversal(root->left, v);
    v.push_back(root->val);
    inorderTraversal(root->right, v);
}

vector<int> merge(vector<int> &v, int mid) {
    vector<int> ans(v.size(), 0);
    int pos = 0;
    for (int i = 0, j = mid; i < mid || j < v.size();) {
        if (i == mid) ans[pos++] = v[j++];
        else if (j == v.size()) ans[pos++] = v[i++];
        else if (v[i] <= v[j]) { ans[pos++] = v[i++]; }
        else { ans[pos++] = v[j++]; }
    }
    return ans;
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> v;
    v.reserve(10000);
    inorderTraversal(root1, v);
    int size1 = v.size();
    inorderTraversal(root2, v);
    return merge(v, size1);
}

int main() {

}
#include "alg.h"

TreeNode *buildTree(vector<int> &preorder, int &start, vector<int> &inorder, int low, int high) {
    int i = low;
    for (; i <= high && inorder[i] != preorder[start]; i++);
    if (i > high) return nullptr;
    TreeNode *root = new TreeNode(preorder[start]);
    start++;
    root->left = buildTree(preorder, start, inorder, low, i - 1);
    root->right = buildTree(preorder, start, inorder, i + 1, high);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int start = 0;
    return buildTree(preorder, start, inorder, 0, inorder.size() - 1);
}


TreeNode *
traversal(vector<int> &preorder, int &pre_idx, vector<int> &inorder, int low, int high, unordered_map<int, int> &v2p) {
    if (pre_idx >= preorder.size() || low > high) return nullptr;
    TreeNode *root = new TreeNode(preorder[pre_idx]);
    int root_idx = v2p[preorder[pre_idx]];
    pre_idx += 1;
    root->left = traversal(preorder, pre_idx, inorder, low, root_idx - 1, v2p);
    root->right = traversal(preorder, pre_idx, inorder, root_idx + 1, high, v2p);
    return root;
}

TreeNode *buildTree_2(vector<int> &preorder, vector<int> &inorder) {
    int pre_idx = 0;
    unordered_map<int, int> v2p;
    for (int i = 0; i < inorder.size(); i++) {
        v2p[inorder[i]] = i;
    }
    return traversal(preorder, pre_idx, inorder, 0, inorder.size() - 1, v2p);
}

int main() {
//    vector<int> pv = {3, 9, 20, 15, 7};
//    vector<int> iv = {9, 3, 15, 20, 7};
    vector<int> pv = {1};
    vector<int> iv = {1};
    print_tree(buildTree(pv, iv));
}
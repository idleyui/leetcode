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

// todo

int main() {
//    vector<int> pv = {3, 9, 20, 15, 7};
//    vector<int> iv = {9, 3, 15, 20, 7};
    vector<int> pv = {1};
    vector<int> iv = {1};
    print_tree(buildTree(pv, iv));
}
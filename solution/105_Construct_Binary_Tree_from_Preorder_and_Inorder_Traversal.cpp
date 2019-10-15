#include "alg.h"

int r = 0;

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int low, int high) {
    TreeNode *root = new TreeNode(preorder[r]);
    if (r >= preorder.size())return nullptr;
    int new_root = low;
    for (; new_root < high && inorder[new_root] != preorder[r]; new_root++);
    if (new_root == high) return nullptr;
    r++;
    root->left = buildTree(preorder, inorder, low, new_root);
    root->right = buildTree(preorder, inorder, new_root + 1, high);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    r = 0;
    return buildTree(preorder, inorder, 0, inorder.size());
}

int main() {
//    vector<int> pv = {3, 9, 20, 15, 7};
//    vector<int> iv = {9, 3, 15, 20, 7};
    vector<int> pv = {1};
    vector<int> iv = {1};
    print_tree(buildTree(pv, iv));
}
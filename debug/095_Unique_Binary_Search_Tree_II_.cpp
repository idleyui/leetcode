#include "alg.h"

TreeNode *clone(TreeNode *root) {
    if (root == nullptr)
        return nullptr;
    TreeNode *newroot = new TreeNode(root->val);
    newroot->left = clone(root->left);
    newroot->right = clone(root->right);
    return newroot;
}

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> res(1, nullptr);
    for (int i = 1; i <= n; i++) {
        vector<TreeNode *> tmp;
        for (int j = 0; j < res.size(); j++) {
            TreeNode *oldroot = res[j];
            TreeNode *root = new TreeNode(i);
            TreeNode *target = clone(oldroot);
            root->left = target;
            tmp.push_back(root);

            if (oldroot != nullptr) {
                TreeNode *tmpold = oldroot;
                while (tmpold->right != nullptr) {
                    TreeNode *nonroot = new TreeNode(i);
                    TreeNode *tright = tmpold->right;
                    tmpold->right = nonroot;
                    nonroot->left = tright;
                    TreeNode *target = clone(oldroot);
                    tmp.push_back(target);
                    tmpold->right = tright;
                    tmpold = tmpold->right;
                }
                tmpold->right = new TreeNode(i);
                TreeNode *target = clone(oldroot);
                tmp.push_back(target);
                tmpold->right = nullptr;
            }
        }
        res = tmp;
    }
    return res;
}

long long f(int n){
    vector<long long> v = {0};
    long long mul = 1;
    for(int i = 1; i <= 2*n; i++){
        mul *= i;
        v.push_back(mul);
    }
    return v[2*n]/(v[n]*v[n+1]);
}

int main() {
    auto lst = generateTrees(10);
//    for(TreeNode *node: generateTrees(15))
//        print_tree(node);
    cout << lst.size() << endl;
    cout << f(10);
}
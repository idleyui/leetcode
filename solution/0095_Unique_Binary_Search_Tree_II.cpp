#include "alg.h"


TreeNode *cp(TreeNode *root) {
    if (!root) return NULL;
    TreeNode *c = new TreeNode(root->val);
    c->left = cp(root->left);
    c->right = cp(root->right);
    return c;
}

bool put(TreeNode *root, int val, int bound) {
    if (!root) return false;
    if (val < root->val) {
        if (put(root->left, val, bound))
            return true;
        else if (root->val == bound) {
            root->val = val;
            return true;
        } else {
            return false;
        }
    } else if (val > root->val) {
        if (put(root->right, val, bound))
            return true;
        else
            return false;
    }
}

vector<TreeNode *> generateTrees(int n) {
    if (n == 0) return {};
    vector<vector<TreeNode *>> dp(n + 1, vector<TreeNode *>());
    dp[1] = {new TreeNode(n + 1)};
    for (int i = 2; i <= n; i++) {//fill dp n
        //         plus one
        for (TreeNode *no: dp[i - 1]) {
            TreeNode *lnode = new TreeNode(n + 1);
            lnode->left = cp(no);
            TreeNode *rnode = new TreeNode(n + 1);
            rnode->right = cp(no);
            dp[i].push_back(lnode);
            dp[i].push_back(rnode);
        }
        for (int j = 0; j < n; j++) {//left have 0~n-1
            int left_num = j, right_num = i - j - 1;
            if (left_num != right_num) {
                for (TreeNode *lnode: dp[left_num]) {
                    for (TreeNode *rnode: dp[right_num]) {
                        TreeNode *node = new TreeNode(n + 1);
                        node->left = cp(lnode);
                        node->right = cp(rnode);
                        dp[i].push_back(node);
                    }
                }
            } else {
                for (int m = 0; m < dp[left_num].size(); m++) {
                    for (int k = m; k < dp[left_num].size(); k++) {
                        TreeNode *node = new TreeNode(n + 1);
                        node->left = cp(dp[left_num][m]);
                        node->right = cp(dp[left_num][k]);
                        dp[i].push_back(node);
                    }
                }
            }
        }
    }
    for (TreeNode *node: dp[n]) {
        for (int i = 1; i <= n; i++) {
            put(node, i, n + 1);
        }
    }
    return dp[n];
}

int main() {
    vector<TreeNode *> v = generateTrees(10);
//    for (TreeNode *n: v) {
//        print_tree(n);
//    }
    cout << v.size();
}
//[[5,4,null,3,null,2,null,1],[1,null,5,4,null,3,null,2],[4,3,5,2,null,null,null,1],[5,1,null,null,4,3,null,2],[1,null,2,null,5,4,null,3],[2,1,5,null,null,4,null,3],[5,3,null,2,4,1],[1,null,4,3,5,2],[5,4,null,1,null,null,3,2],[1,null,5,2,null,null,4,3],[4,1,5,null,3,null,null,2],[5,1,null,null,2,null,4,3],[1,null,2,null,3,null,5,4],[2,1,3,null,null,null,5,4],[5,2,null,1,4,null,null,3],[1,null,3,2,5,null,null,4],[5,4,null,3,null,1,null,null,2],[1,null,5,4,null,2,null,null,3],[4,3,5,1,null,null,null,null,2],[5,1,null,null,4,2,null,null,3],[1,null,2,null,5,3,null,null,4],[2,1,5,null,null,3,null,null,4],[5,3,null,1,4,null,2],[1,null,4,2,5,null,3],[5,4,null,1,null,null,2,null,3],[1,null,5,2,null,null,3,null,4],[4,1,5,null,2,null,null,null,3],[5,1,null,null,2,null,3,null,4],[1,null,2,null,3,null,4,null,5],[2,1,3,null,null,null,4,null,5],[5,2,null,1,3,null,null,null,4],[1,null,3,2,4,null,null,null,5],[5,4,null,2,null,1,3],[1,null,5,3,null,2,4],[4,2,5,1,3],[5,1,null,null,3,2,4],[1,null,2,null,4,...
//[[1,null,2,null,3,null,4,null,5],[1,null,2,null,3,null,5,4],[1,null,2,null,4,3,5],[1,null,2,null,5,3,null,null,4],[1,null,2,null,5,4,null,3],[1,null,3,2,4,null,null,null,5],[1,null,3,2,5,null,null,4],[1,null,4,2,5,null,3],[1,null,4,3,5,2],[1,null,5,2,null,null,3,null,4],[1,null,5,2,null,null,4,3],[1,null,5,3,null,2,4],[1,null,5,4,null,2,null,null,3],[1,null,5,4,null,3,null,2],[2,1,3,null,null,null,4,null,5],[2,1,3,null,null,null,5,4],[2,1,4,null,null,3,5],[2,1,5,null,null,3,null,null,4],[2,1,5,null,null,4,null,3],[3,1,4,null,2,null,5],[3,1,5,null,2,4],[3,2,4,1,null,null,5],[3,2,5,1,null,4],[4,1,5,null,2,null,null,null,3],[4,1,5,null,3,null,null,2],[4,2,5,1,3],[4,3,5,1,null,null,null,null,2],[4,3,5,2,null,null,null,1],[5,1,null,null,2,null,3,null,4],[5,1,null,null,2,null,4,3],[5,1,null,null,3,2,4],[5,1,null,null,4,2,null,null,3],[5,1,null,null,4,3,null,2],[5,2,null,1,3,null,null,null,4],[5,2,null,1,4,null,null,3],[5,3,null,1,4,null,2],[5,3,null,2,4,1],[5,4,null,1,null,null,2,null,3],[5,...


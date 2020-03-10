#include "alg.h"


int cnt = 0;

vector<int> result_list(TreeNode *root, int sum) {
    if (!root) return {};
    vector<int> left_rt = result_list(root->left, sum);
    vector<int> right_rt = result_list(root->right, sum);
    vector<int> rt;
    for (int i: left_rt) {
        int val = i + root->val;
        // cout << val;
        if (val == sum) cnt++;
        rt.push_back(val);
    }
    for (int i: right_rt) {
        int val = i + root->val;
        // cout << val;
        if (val == sum) cnt++;
        rt.push_back(val);
    }
    if (root->val == sum) cnt++;
    rt.push_back(root->val);
    return rt;
}

int pathSum(TreeNode *root, int sum) {
    result_list(root, sum);
    return cnt;
}

int main() {

}
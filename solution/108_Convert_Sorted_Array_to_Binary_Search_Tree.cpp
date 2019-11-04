#include "alg.h"

TreeNode *tobst(vector<int> &nums, int begin, int end) {
    if (end < begin) return nullptr;
    int mid = (begin + end) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = tobst(nums, begin, mid - 1);
    root->right = tobst(nums, mid + 1, end);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    return tobst(nums, 0, nums.size() - 1);
}

int main() {

}
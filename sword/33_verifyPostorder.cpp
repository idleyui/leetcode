#include "alg.h"

// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
bool verifyPostorder(vector<int> &postorder, int low, int high) {
    if (low >= high) return true;
    int mid = postorder[high];
    int right = low;
    for (; right < high && postorder[right] < mid; right++);
    for (int tmp = right; tmp < high; tmp++) { if (postorder[tmp] < mid) return false; }
    return verifyPostorder(postorder, low, right - 1) && verifyPostorder(postorder, right, high - 1);
}

bool verifyPostorder(vector<int> &postorder) {
    return verifyPostorder(postorder, 0, postorder.size() - 1);
}

// stack
bool verifyPostorder_2(vector<int> &postorder) {
    stack<int> stk;
    int prev = INT_MAX;
    for (int i = postorder.size() - 1; i >= 0; i--) {
        if (postorder[i] > prev) return false;
        while (!stk.empty() && postorder[i] < stk.top()) {
            prev = stk.top();
            stk.pop();
        }
        stk.push(postorder[i]);
    }
    return true;
}

int main() {

}
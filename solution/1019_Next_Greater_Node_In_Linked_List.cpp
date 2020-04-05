#include "alg.h"

vector<int> nextLargerNodes_1(ListNode *head) {
    stack<int> stk;
    stack<int> idx_stk;
    vector<int> ans(10000, 0);

    int idx = 0;
    while (head) {
        while (!stk.empty() && stk.top() < head->val) {
            ans[idx_stk.top()] = head->val;
            idx_stk.pop();
            stk.pop();
        }
        stk.push(head->val);
        idx_stk.push(idx++);
        head = head->next;
    }

    return vector<int>(ans.begin(), ans.begin() + idx);
}

//https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/265508/JavaC%2B%2BPython-Next-Greater-Element
//put index in stack, val in vector
vector<int> nextLargerNodes_2(ListNode *head) {
    vector<int> res, stk;
    while (head) {
        while (!stk.empty() && res[stk.back()] < head->val) {
            res[stk.back()] = head->val;
            stk.pop_back();
        }
        stk.push_back(res.size());
        res.push_back(head->val);
        head = head->next;
    }
    for (int i: stk) res[i] = 0;
    return res;
}

int main() {

}
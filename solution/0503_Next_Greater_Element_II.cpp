#include "alg.h"

vector<int> nextGreaterElement_single_loop(vector<int> nums) {
    stack<int> stk;
    vector<int> next_gt(nums.size(), -1);
    for (int i = 0; i < nums.size(); i++) {
        while(!stk.empty() && nums[i] > nums[stk.top()]){
            next_gt[stk.top()] = nums[i];
            stk.pop();
        }
        stk.push(i);
    }
    return next_gt;
}

// push the indexes in the stack not the elements
// https://leetcode.com/problems/next-greater-element-ii/discuss/98270/JavaC%2B%2BPython-Loop-Twice
vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> next_gt(n, -1);
    for (int i = 0; i < n*2; i++) {
        while(!stk.empty() && nums[i%n] > nums[stk.top()]) {
            next_gt[stk.top()] = nums[i%n];
            stk.pop();
        }
        if(i < n) stk.push(i%n);
    }
    return next_gt;
}

int main() {
    print_container(nextGreaterElement_single_loop({2,1,3,4,5,12,3,4}));
}
#include "alg.h"

//https://leetcode.com/problems/sliding-window-maximum/discuss/65898/Clean-C%2B%2B-O(n)-solution-using-a-deque
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> rt;
    for (int i = 0; i < nums.size(); ++i) {
        if (!dq.empty() && dq.front() == i - k)dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)rt.push_back(nums[dq.front()]);
    }
    return rt;

}

int main() {

}
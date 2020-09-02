#include "alg.h"

// head & tail pointer
vector<int> exchange(vector<int> &nums) {
    int l = 0, h = nums.size() - 1;
    while (l < h) {
        for (; l < h && nums[l] % 2 != 0; l++);
        if (l >= h) break;
        for (; l < h && nums[h] % 2 == 0; h--);
        if (l >= h) break;
        swap(nums[l++], nums[h--]);
    }
    return nums;
}

// fast & slow pointer
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/ti-jie-shou-wei-shuang-zhi-zhen-kuai-man-shuang-zh/
vector<int> exchange_2(vector<int> &nums) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] % 2 == 1) swap(nums[slow++], nums[fast]);
        fast++;
    }
    return nums;
}

int main() {

}
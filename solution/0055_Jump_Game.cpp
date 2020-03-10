#include "alg.h"

// Solution 1: linear loop
bool canJump1(vector<int> &nums) {
    int i = 0;
    int max_step = nums[i];
    for (i = 1; i < nums.size() && i <= max_step; i++) {
        max_step = max(i + nums[i], max_step);
    }
    return i == nums.size();
}

// Better version
// https://leetcode.com/problems/jump-game/discuss/20917/Linear-and-simple-solution-in-C%2B%2B
bool canJump1_(vector<int> &nums){
    int i = 0;
    for(int reach = 0; i < nums.size() && i <= reach; i++){
        reach = max(reach, nums[i] + i);
    }
    return i == nums.size();
}

// Solution 2: search backwards
// https://leetcode.com/problems/jump-game/discuss/20900/Simplest-O(N)-solution-with-constant-space
bool canJump2(vector<int> &nums) {
    int last_idx = nums.size() - 1;
    for (int i = last_idx - 1; i >= 0; i--) {
        if (nums[i] + i >= last_idx) last_idx = i;
    }
    return last_idx == 0;
}

int main() {

}
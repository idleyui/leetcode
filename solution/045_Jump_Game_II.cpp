#include "alg.h"

// Solution 1: BFS: find max next reach in a reach
// https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
int jump1(vector<int> &nums) {
    if (nums.size() < 2) return 0;
    int reach = nums[0];
    int last_reach = min(nums[0], (int) nums.size() - 1);
    int jump = 0;
    for (int i = 0; i < nums.size() && i <= reach; i++) {
        reach = max(nums[i] + i, reach);
        if (i == last_reach) {
            jump += 1;
            last_reach = min(reach, (int) nums.size() - 1);
        }
    }
    return jump;
}

int main() {

}
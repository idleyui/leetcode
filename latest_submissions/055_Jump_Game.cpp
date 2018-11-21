class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = nums[0], base = nums[0];
        for(int i = 1; i < nums.size() && i <= far && far < nums.size(); i++){
            far = max(far, i+nums[i]);
        }
        return far >= (nums.size() - 1);
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int r = INT_MIN, max_to = 0;
        for(int i = 0; i < nums.size(); i++){
            max_to += nums[i];
            r = max(r, max_to);
            max_to = max(max_to, 0);
            
        }
        return r;
    }
};
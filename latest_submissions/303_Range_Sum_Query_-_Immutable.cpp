class NumArray {
public:
    vector<int> mdp;
    int max;
    
    NumArray(vector<int> nums) {
        max = nums.size();
        vector<int> dp(nums.size()+1, 0);
        
        for(int i = 0; i < nums.size(); i++){
            dp[i+1] = dp[i] + nums[i];
        }
        
        mdp = dp;
    }
    
    int sumRange(int i, int j) {
        if (i > j || j >= max)  return 0;
        return mdp[j+1] - mdp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
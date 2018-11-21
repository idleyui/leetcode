class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int jump = 0, far = nums[0];
        for(int i = 1; i < nums.size();){
            if (far >= nums.size()) far = nums.size()-1;

            jump++;
            int m = INT_MIN;
            for(int j = i; j <= far; j++){
                dp[j] = jump;
                cout << j << "-" << jump << "," << endl;
                m = max(m, j+nums[j]);
            }
            i = far + 1;
            far = max(far, m);
            cout << i << "-" << far << endl;
        }
        return dp[nums.size()-1];
    }
};
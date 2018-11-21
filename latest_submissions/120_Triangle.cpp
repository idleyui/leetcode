class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)   return 0;
        vector<int> dp = triangle[triangle.size()-1];
        for(int i = triangle.size()-2; i >= 0; i--){
            vector<int> tmp_dp(triangle[i].size());
            for(int j = 0; j < triangle[i].size(); j++){
                tmp_dp[j] = triangle[i][j] + (dp[j] < dp[j+1]?dp[j]:dp[j+1]);
            }
            dp = tmp_dp;
        }
        return dp[0];
    }
};
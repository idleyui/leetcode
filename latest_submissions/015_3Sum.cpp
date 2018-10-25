class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result{};
        if(nums.size() < 3) return{};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() -2; i++){
            for(int low = i+1, high = nums.size()-1; low < high;){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == 0){
                    result.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }else if(sum < 0)low++;
                else high--;
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};
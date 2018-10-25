class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> result = {};
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                for (int low = j + 1, high = nums.size() - 1; low < high;) {
                    int sum = nums[i] + nums[j] + nums[low] + nums[high];
                    if (sum == target) {
                        result.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++, high--;
                    } else if (sum > target)high--;
                    else low++;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};
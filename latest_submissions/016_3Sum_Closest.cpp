class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = INT_MAX, result = 0;
        if(nums.size() < 3)return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            for(int low = i+1, high = nums.size()-1; low < high;){
                int sum = nums[i] + nums[low] + nums[high];
                int abs = sum > target?(sum - target):(target-sum);
                if(abs < min){
                    min = abs;
                    result = sum;
                }
                if(sum == target)return sum;
                else if(sum < target)low++;
                else high--;
            }
        }
        return result;
    }
};
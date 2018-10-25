class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> p2v{};
        for(int i = 0; i < nums.size(); i++){
            int tosum = target - nums[i];
            if(p2v.count(tosum)){
                return {p2v[tosum], i};
            }
            p2v[nums[i]] = i;
        }
    }
};
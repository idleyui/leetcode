class Solution {
public:
    int search(vector<int>& nums, int low, int high, int target, bool left){
        int pos = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if (nums[mid] == target){
                pos = mid;
                if (left) high = mid-1;
                else low = mid+1;
            } else if (nums[mid] > target){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return pos;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {search(nums, 0, nums.size()-1, target, true), 
                search(nums, 0, nums.size()-1, target, false)
               };
    }
};
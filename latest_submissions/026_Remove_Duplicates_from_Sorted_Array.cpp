class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)return 0;
        int dup_index = 0, free = 0, last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == last) {
                last = nums[i];
                dup_index = dup_index == 0 ? i : dup_index;
                free++;
            } else if (free != 0) {
                last = nums[i];
                swap(nums[i], nums[dup_index++]);
            } else {
                last = nums[i];
            }
        }
        return nums.size() - free;
    }
};
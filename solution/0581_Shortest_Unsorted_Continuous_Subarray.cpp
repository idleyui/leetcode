#include "alg.h"

int findUnsortedSubarray(vector<int> nums) {
    int max_val = INT_MIN;
    int begin = -1, end = -2;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < max_val) {
            begin = begin == -1 ? i - 1 : begin - 1;
            for (; begin >= 0 && nums[begin] > nums[i]; begin--);
            begin++;
            end = i;
        } else {
            max_val = nums[i];
        }
    }
    return end - begin + 1;
}

int main() {
    cout << findUnsortedSubarray({1, 2, 3, 4, 5}) << endl;
    cout << findUnsortedSubarray({2, 1}) << endl;
    cout << findUnsortedSubarray({1, 3, 5, 4, 2}) << endl;
}
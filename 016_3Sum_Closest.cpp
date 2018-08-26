#include "alg.h"

int threeSumClosest(vector<int> &nums, int target) {
    int result = 0, min = INT_MAX;
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        for (int low = i + 1, high = nums.size() - 1; low < high;) {
            int sum = nums[i] + nums[low] + nums[high];
            int abso = sum > target ? sum - target : target - sum;
            if (abso < min) {
                result = sum;
                min = abso;
            }
            if (sum < target) low++;
            else if (sum > target)high--;
            else return sum;
        }
    }
    return result;
}

int main() {
//    vector<int> v{0, 1, 2};
    vector<int> v1{-1,2,1,-4};
//    cout << threeSumClosest(v, 3);
    cout << threeSumClosest(v1, 1);
}

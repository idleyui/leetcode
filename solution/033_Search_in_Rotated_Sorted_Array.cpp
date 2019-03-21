#include "alg.h"

bool contain(int low, int high, int target) {
    return low <= target && high >= target;
}

bool out(int high, int low, int target) {
    return target >= high || target <= low;
}

int search(vector<int> &nums, int target) {
    if(nums.size() == 0) return -1;
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (target == nums[mid]) return mid;
        if (nums[low] < nums[mid] && contain(nums[low], nums[mid], target))
            high = mid - 1;
        else if (nums[mid] < nums[high] && contain(nums[mid], nums[high], target))
            low = mid + 1;
        else if (nums[low] > nums[mid] && out(nums[low], nums[mid], target))
            high = mid - 1;
        else if (nums[mid] > nums[high] && out(nums[mid], nums[high], target))
            low = mid + 1;
        else return -1;
    }
//    return -1;
}

int test(int i){
    int num = 3;
    if (i > 0)return 1;
}

int main() {
//    vector<int> v = mkv({4, 5, 6, 7, 0, 1, 2});
//    cout << search(v, 0);
//    cout << search(v, 3);
    int a = 0;
    cout << test(a);
}
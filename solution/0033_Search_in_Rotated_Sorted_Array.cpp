#include "alg.h"

// clever idea
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
int searchInf(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        double num = (nums[mid] < nums[0]) == (target < nums[0])
                     ? nums[mid]
                     : target < nums[0] ? -INFINITY : INFINITY;
        if (num < target) low = mid + 1;
        else if (num > target) high = mid - 1;
        else return mid;
    }
    return -1;
}


// use twice binary search
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution
int searchTwice(vector<int> &nums, int target) {
    int n = nums.size(), l = 0, h = n - 1;
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] <= nums[h]) { h = mid; }
        else { l = mid + 1; }
    }

    if (target <= nums[0]) { h = n - 1; }
    else {
        h = l - 1;
        l = 0;
    }

    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] == target) { return mid; }
        else if (nums[mid] > target) { h = mid - 1; }
        else { l = mid + 1; }
    }
    return -1;
}

// naive version
bool contain(int low, int high, int target) {
    return low <= target && high >= target;
}

bool out(int high, int low, int target) {
    return target >= high || target <= low;
}

//https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14472/Java-AC-Solution-using-once-binary-search
int search(vector<int> &nums, int target) {
    if (nums.size() == 0) return -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
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
    return -1;
}

int search4(vector<int> &nums, int target) {
    if (nums.empty()) return -1;
    int l = 0, h = nums.size() - 1;
    bool inleft = target >= nums[0];
    while (l <= h) {
        int mid = l + (h - l) / 2;
        //cout << l << ' ' << h << ' ' << mid << endl;

        bool midinleft = nums[mid] >= nums[0];
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) {
            if (inleft && midinleft) l = mid + 1;
            if (!inleft && !midinleft) l = mid + 1;
            if (inleft && !midinleft) h = mid - 1;
        } else if (nums[mid] > target) {
            if (inleft && midinleft) h = mid - 1;
            if (!inleft && !midinleft) h = mid - 1;
            if (!inleft && midinleft) l = mid + 1;
        }
    }
    return -1;
}

int test(int i) {
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
#include "alg.h"

// sort and find
int findRepeatNumber_1(vector<int> nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) return nums[i];
    }
    return -1;
}

// use visited set
int findRepeatNumber_2(vector<int> nums) {
    unordered_set<int> visited;
    for (int i: nums) {
        if (visited.count(i)) return i;
        visited.insert(i);
    }
    return -1;
}

// 利用 0 <= num <= n-1 这一点
// tips: 看到数字有范围且范围不大，就可以考虑使用数组来替代 排序/哈希 过程
int findRepeatNumber_3(vector<int> nums) {
    vector<int> visited(nums.size(), 0);
    for (int num: nums) {
        if (visited[num] > 0) return num;
        visited[num] += 1;
    }
    return -1;
}

// 因为 length = 数字范围，所以将所有数字换到自己的值的位置上去
int findRepeatNumber(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (i == num) continue;
        if (nums[num] == num) return num;
        swap(nums[i], nums[num]);
    }
    return -1;
}


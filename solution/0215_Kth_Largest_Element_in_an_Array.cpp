#include "alg.h"

int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; i++) {
        q.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > q.top()) {
            q.pop();
            q.push(nums[i]);
        }
    }

    return q.top();
}

int partition(vector<int> &nums, int l, int h) {
    int val = nums[l + (h - l) / 2];
    l--;
    h++;
    while (l < h) {
        do l++; while (nums[l] < val);
        do h--; while (nums[h] > val);
        if (l < h) swap(nums[l], nums[h]);
    }
    return h;
}

// quick select
int findKthLargest_2(vector<int> &nums, int k) {
    int l = 0, h = nums.size() - 1;
    k = nums.size() - k;
    while (l < h) {
        int mid = partition(nums, l, h);
        if (k <= mid) h = mid;
        else l = mid + 1;
    }
    return nums[h];
}

int main() {

}
#include "alg.h"


bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> window;
    for (int i = 0; i < k && i < nums.size(); i++) {
        if (window[nums[i]] > 0) return true;
        window[nums[i]]++;
    }
    for (int i = k; i < nums.size(); i++) {
        if (window[nums[i]] > 0) return true;
        window[nums[i - k]]--;
        window[nums[i]]++;
    }
    return false;
}

int main() {

}
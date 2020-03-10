#include "alg.h"

vector<vector<int>> threeSum(vector<int> &nums) {
    set<vector<int>> result = {};
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)return {};
    for (int i = 0; i < nums.size() - 2; ++i) {
        for (int low = i + 1, high = nums.size() - 1; low < high;) {
            int sum = nums[i] + nums[low] + nums[high];
            if (sum == 0) {
                result.insert({nums[i], nums[low], nums[high]});
                low++, high--;
            } else if (sum > 0) high--;
            else low++;
        }
    }
    return vector<vector<int>>(result.begin(), result.end());
}

// handle duplication; early break
//https://leetcode.com/problems/3sum/discuss/7438/C%2B%2B-two-pointes-solution-(easy-way-to-handle-duplicaiton).
// but this link has out-of-range bug
vector<vector<int>> threeSumBest(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size();) {
        for (int low = i + 1, high = nums.size() - 1; low < high;) {
            if (nums[i] > 0) break;
            int sum = nums[i] + nums[low] + nums[high];
            if (sum == 0) {
                result.push_back({nums[i], nums[low], nums[high]});
                int low_val = nums[low];
                while (low < nums.size() && nums[low] == low_val)low++;
                int high_val = nums[high];
                while (high >= 0 && nums[high] == high_val)high--;
            } else if (sum < 0) {
                low++;
            } else if (sum > 0) {
                high--;
            }
        }
        int i_val = nums[i];
        while (i < nums.size() && nums[i] == i_val) i++;
    }
    return result;
}


// use two sum method inside
vector<vector<int>> threeSum1(vector<int> &nums) {
    set<vector<int>> result = {};
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)return {};
    for (int i = 0; i < nums.size() - 2; ++i) {
        int sum = -nums[i];
        map<int, int> v2p;
        for (int j = i + 1; j < nums.size(); ++j) {
            int supple = sum - nums[j];
            if (v2p.find(supple) != v2p.end()) {
                result.insert({nums[i], supple, nums[j]});
            }
            v2p.insert({nums[j], j});
        }
    }
    return vector<vector<int>>(result.begin(), result.end());
}

int main() {
    vector<int> v1 = {-2, 0, 1, 1, 2};
    for (auto v: threeSum(v1)) {
        for (auto i: v) {
            cout << i << ',';
        }
        cout << endl;
    }
}
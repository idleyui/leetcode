#include "alg.h"

//todo
vector<vector<int>> threeSum(vector<int> &nums) {
    set<vector<int>> result = {};
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)return {};
    for (int i = 0; i < nums.size() - 2; ++i) {
        for (int low = i + 1, high = nums.size()-1; low < high;) {
            int sum = nums[i] + nums[low] + nums[high];
            if (sum == 0) {
                result.insert({nums[i], nums[low], nums[high]});
                low++, high--;
            }
            else if (sum > 0)    high--;
            else low++;
        }
    }
    return vector<vector<int>>(result.begin(), result.end());
}

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
    vector<int> v1 = {-2,0,1,1,2};
    for(auto v: threeSum(v1)){
        for(auto i: v){
            cout << i << ',';
        }
        cout << endl;
    }
}
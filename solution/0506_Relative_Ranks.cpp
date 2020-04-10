#include "alg.h"

vector<string> findRelativeRanks_1(vector<int> &nums) {
    vector<pair<int, int>> score_idx;
    score_idx.reserve(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        score_idx.push_back({nums[i], i});
    }
    sort(score_idx.begin(), score_idx.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first > p2.first;
    });
    vector<string> ans(nums.size(), "");
    string medal[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    for (int i = 0; i < 3 && i < score_idx.size(); i++) {
        ans[score_idx[i].second] = medal[i];
    }
    for (int i = 3; i < score_idx.size(); i++) {
        ans[score_idx[i].second] = to_string(i + 1);
    }
    return ans;
}

// Solution 2: use map val->idx
//https://leetcode.com/problems/relative-ranks/discuss/98578/Simple-C%2B%2B-solution-using-a-map

int main() {

}
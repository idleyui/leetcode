#include "alg.h"

// dp[i] = dp[i-1] i not in days
// dp[i] = min(dp[i-1] + cost0, dp[i-7] + cost1, dp[i-30] + cost2)
int mincostTickets0(vector<int> &days, vector<int> &costs) {
    vector<int> dp(366, 0);

    for (int i = 1; i <= days.back(); i++) {
        if (find(days.begin(), days.end(), i) == days.end()) {
            dp[i] = dp[i - 1];
            continue;
        }
        dp[i] = min({dp[i - 1] + costs[0], dp[max(i - 7, 0)] + costs[1], dp[max(i - 30, 0)] + costs[2]});
        // cout << dp[i] << ' ';
    }
    return dp[days.back()];
}

// Solution 2: track travel days
// https://leetcode.com/problems/minimum-cost-for-tickets/discuss/226659/Two-DP-solutions-with-pictures
int mincostTickets1(vector<int> &days, vector<int> &costs) {
    queue<pair<int, int>> last7, last30;
    int cost = 0;
    for (int day: days) {
        while (!last7.empty() && last7.front().first + 7 <= day) last7.pop();
        while (!last30.empty() && last30.front().first + 30 <= day) last30.pop();
        last7.push({day, cost + costs[1]});
        last30.push({day, cost + costs[2]});
        cost = min({cost + costs[0], last7.front().second + costs[1], last30.front().second + costs[2]});
    }
    return cost;
}

int main() {

}
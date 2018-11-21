class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int l = cost[0], r = cost[1];
        for(int i = 2; i < cost.size(); i++){
            int tmp_min = cost[i] + min(l, r);
            l = r;
            r = tmp_min;
        }
        return min(l, r);
    }
};
#include "alg.h"

// min_cost_i = min(min_cost_[i-1], min_cost_[i-2]) + cost_i
int minCostClimbingStairs(vector<int> &cost) {
    int one_step_back = 0, two_step_back = 0;
    for (int i: cost) {
        int c = i + min(one_step_back, two_step_back);
        two_step_back = one_step_back;
        one_step_back = c;
    }
    return min(one_step_back, two_step_back);
}

int main() {

}
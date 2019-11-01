#include "alg.h"


unordered_map<int, int> amount2val = {{0, 0}};

int coinChange(vector<int> &coins, int amount) {
    // cout << amount;
    if (amount2val.count(amount)) return amount2val[amount];
    if (amount < 0) return -1;
    int min_val = -1;
    for (int i: coins) {
        int change = coinChange(coins, amount - i);
        amount2val[amount - i] = change;
        if (change >= 0) min_val = min_val == -1 ? (change + 1) : min(min_val, change + 1);
    }
    return min_val > 0 ? min_val : -1;
}

int main() {

}
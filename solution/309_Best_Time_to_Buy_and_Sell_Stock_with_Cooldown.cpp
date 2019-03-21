#include "alg.h"

int maxProfit(vector<int>& prices) {
    if (prices.size() < 2)  return 0;
    vector<int> tobuy(prices.size(), 0);
    vector<int> hold(prices.size(), 0);
    vector<int> rest(prices.size(), 0);
    hold[0] = -prices[0];
    rest[0] = INT_MIN;
    for(int i = 1; i < prices.size(); i++){
        tobuy[i] = max(tobuy[i-1], rest[i-1]);
        hold[i]  = max(tobuy[i-1]-prices[i], hold[i-1]);
        rest[i]  = hold[i-1]+prices[i];
    }
    return max(tobuy[prices.size()-1], rest[prices.size()-1]);
}

int main() {

}
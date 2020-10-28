#include "alg.h"

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        if (prices.empty() || prices.back() > price) {
            prices.push_back(price);
            last_great.push_back(prices.size() - 2);
        } else {
            int i = last_great.back();
            while (i >= 0 && prices[i] <= price) i = last_great[i];
            last_great.push_back(i);
            prices.push_back(price);
        }
        return prices.size() - 1 - last_great.back();
    }

private:
    vector<int> prices;
    vector<int> last_great;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

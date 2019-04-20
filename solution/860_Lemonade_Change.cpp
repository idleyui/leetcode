#include "alg.h"

bool lemonadeChange(vector<int> &bills) {
    int five = 0;
    int ten = 0;
    int twenty = 0;
    for (int i: bills) {
        if (i == 5) { five++; }
        else if (i == 10) {
            five--;
            if (five < 0) return false;
            ten++;
        } else if (i == 20) {
            if (ten > 0) {
                ten--;
                five--;
            } else {
                five -= 3;
            }
            if (five < 0 || ten < 0)return false;
            twenty++;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> vv = {
            {5,  5, 5,  10, 20},
            {10, 5, 5,  10, 20},
            {5,  5, 10},
            {10, 10},
            {5,  5, 10, 10, 20}
    };
    for (auto v: vv)
        cout << lemonadeChange(v) << endl;
}
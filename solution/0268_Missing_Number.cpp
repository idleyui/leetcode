#include "alg.h"

int missingNumber(vector<int> &nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); i++) {
        num = num ^ i;
        num = num ^ nums[i];
    }
    return num ^ nums.size();
}

int main() {

}
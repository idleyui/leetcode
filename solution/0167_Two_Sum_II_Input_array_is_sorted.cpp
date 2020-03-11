#include "alg.h"

// todo discuss
vector<int> twoSum(vector<int> &numbers, int target) {
    for (int l = 0, h = numbers.size() - 1; l < h;) {
        int sum = numbers[l] + numbers[h];
        if (sum == target) return {l + 1, h + 1};
        else if (sum > target) h--;
        else l++;
    }
    return {-1, -1};
}

int main() {

}
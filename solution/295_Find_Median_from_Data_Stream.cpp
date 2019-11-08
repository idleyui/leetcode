#include "alg.h"

//todo optim
class MedianFinder {
private:
    vector<int> nums;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        auto item = nums.begin();
        for (; item != nums.end() && *item <= num; item++);
        nums.insert(item, num);
    }

    double findMedian() {
        int n = nums.size();
        if (n % 2 == 0) return (nums[n / 2] + nums[n / 2 - 1]) / 2.0;
        else return nums[n / 2];
    }
};

int main() {
}
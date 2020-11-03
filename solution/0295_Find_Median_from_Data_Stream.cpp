#include "alg.h"

class MedianFinder {
private:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            if (minHeap.empty()) {
                minHeap.push(num);
            } else if (num < maxHeap.top()) {
                int tmp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(tmp);
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
        } else {
            if (num > minHeap.top()) {
                int tmp = minHeap.top();
                minHeap.pop();
                maxHeap.push(tmp);
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (double) (maxHeap.top() + minHeap.top()) / 2;
        } else {
            return minHeap.top();
        }
    }
};

int main() {
}
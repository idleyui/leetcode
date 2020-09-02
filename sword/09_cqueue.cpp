#include "alg.h"

// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/solution/mian-shi-ti-09-yong-liang-ge-zhan-shi-xian-dui-l-2/
// use one stack for enqueue, one for dequeue
class CQueue {

public:

    CQueue() {
    }

    void appendTail(int value) {
        in_stk.push(value);
    }

    int deleteHead() {
        if (!out_stk.empty()) {
            int ans = out_stk.top();
            out_stk.pop();
            return ans;
        }
        if (in_stk.empty()) return -1;
        while (!in_stk.empty()) {
            out_stk.push(in_stk.top());
            in_stk.pop();
        }
        return deleteHead();
    }

private:

    stack<int> in_stk;
    stack<int> out_stk;

};

int main() {

}
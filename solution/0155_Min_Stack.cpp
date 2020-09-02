#include "alg.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || min_stk.top() >= x) min_stk.push(x);
    }

    void pop() {
        if (stk.top() == min_stk.top()) min_stk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }

private:

    stack<int> stk;
    stack<int> min_stk;
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin();
    minStack.pop();
    cout << minStack.top();
    cout << minStack.getMin();
}
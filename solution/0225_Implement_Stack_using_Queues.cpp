#include "alg.h"

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        set();
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        set();
        while (q.size() > 1) {
            int x = q.front();
            q.pop();
            eq.push(x);
        }
        int x = q.front();
        q.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        set();
        int x = 0;
        while (!q.empty()) {
            x = q.front();
            q.pop();
            eq.push(x);
        }
        return x;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
    queue<int> &q = q1;
    queue<int> &eq = q2;

    void set() {
        if(q.empty()) swap(q, eq);
    }
};

int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;   // returns 2
    cout << stack.pop() << endl;   // returns 2
    cout << stack.pop() << endl;   // returns 2
    cout << stack.empty() << endl; // returns false
}
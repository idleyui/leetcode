#include "alg.h"

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (!s2.empty()) set();
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) set();
        int x = s2.top();
        s2.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) set();
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    bool last = false;
    stack<int> s1;
    stack<int> s2;

    void change(stack<int> &s, stack<int> &es) {
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            es.push(x);
        }
    }

    void set() {
        if (!s2.empty())change(s2, s1);
        else change(s1, s2);
    }
};

int main() {
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;  // returns 1
    cout << queue.pop() << endl;   // returns 1
    cout << queue.pop() << endl;   // returns 1
    cout << queue.empty() << endl; // returns false
}
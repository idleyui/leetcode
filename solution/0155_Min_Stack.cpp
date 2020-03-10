#include "alg.h"

class MinStack {
public:
    MinStack() {
        arr = new int[10];
        size = 0;
        capable = 10;
    }

    void push(int x) {
        if (size == capable) { resize(); }
        arr[size++] = x;
    }

    void pop() {
        if (size > 0)size--;
    }

    int top() {
        return arr[size - 1];
    }

    int getMin() {
        int min = INT_MAX;
        for (int i = 0; i < size; ++i) {
            if (arr[i] < min)
                min = arr[i];
        }
        return min;
    }

private:
    int *arr;
    int size;
    int capable;

    void resize() {
        capable = capable * 2;
        int *p = new int[capable];
        copy(arr, arr + size, p);
        delete[] arr;
        arr = p;
    }
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
#include "alg.h"

bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> stk;
    int push = 0, pop = 0;
    while (push < pushed.size() || !stk.empty()) {
        if (!stk.empty() && stk.top() == popped[pop]) {
            stk.pop();
            pop++;
        } else if (push < pushed.size()) {
            stk.push(pushed[push]);
        } else {
            break;
        }
    }
    return stk.empty();
}

// https://leetcode.com/problems/validate-stack-sequences/discuss/197685/C%2B%2BJavaPython-Simulation-O(1)-Space
// simulating
bool validateStackSequences_2(vector<int> &pushed, vector<int> &popped) {
    stack<int> stk;
    int pop = 0;
    for(int i: pushed) {
        stk.push(i);
        while(!stk.empty() && stk.top() == popped[pop]){
            stk.pop();
            pop++;
        }
    }
    return stk.empty();
}

// https://leetcode.com/problems/validate-stack-sequences/discuss/197685/C%2B%2BJavaPython-Simulation-O(1)-Space
// use push as stack
bool validateStackSequences_3(vector<int> &pushed, vector<int> &popped) {
    int stk_end = -1, pop = 0;
    for(int i = 0; i < pushed.size(); i++) {
        pushed[++stk_end] = pushed[i];
        while(stk_end >= 0 && pushed[stk_end] == popped[pop]) {
            stk_end--;
            pop++;
        }
    }
    return stk_end < 0;
}

int main() {

}
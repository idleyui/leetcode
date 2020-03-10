#include "alg.h"

vector<int> nextGreaterElements(vector<int> &nums) {
    unordered_map<int, int> gt;
    stack<int> st;
    for (auto i :nums) {
        while (!st.empty() && st.top() < i) {
            gt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

int main() {

}
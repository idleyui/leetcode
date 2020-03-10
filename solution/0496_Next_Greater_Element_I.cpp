#include "alg.h"

vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2) {
    unordered_map<int, int> gt;
    stack<int> st;
    for (int i: nums2) {
        while (!st.empty() && st.top() < i) {
            gt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> result;
    for (int i : nums1) {
        if (gt.count(i)) {
            result.push_back(gt[i]);
        } else {
            result.push_back(-1);
        }
    }
    return result;
}

int main() {
    print_container(nextGreaterElement({4, 1, 2}, {1, 3, 4, 2}));
    print_container(nextGreaterElement({2, 4}, {1, 2, 3, 4}));
}
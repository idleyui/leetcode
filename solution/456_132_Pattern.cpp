#include "alg.h"

bool find132pattern(vector<int> nums) {
    int s3 = INT_MIN;
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] < s3) return true;
        else {
            while (!st.empty() && nums[i] > st.top()) {
                s3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
    }
    return false;
}

int main() {
    cout << find132pattern({1, 3, 2});
    cout << find132pattern({1, 2, 2, 4});
    cout << find132pattern({3, 1, 4, 2});
    cout << find132pattern({-1, 3, 2, 0});
}
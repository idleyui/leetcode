#include "alg.h"

bool isPossible(vector<int> nums) {
    deque<int> seqs;
    for (int i = 0; i < nums.size();) {
        int j = 0;
        for (; i + j < nums.size() && nums[i + j] == nums[i]; ++j);

        if (j < seqs.size()) {
            size_t n = seqs.size() - j;
            for (int k = 0; k < n; ++k) {
                if (seqs.front() < 3) return false;
                else seqs.pop_front();
            }
        } else if (j > seqs.size()) {
            size_t n = j - seqs.size();
            for (int k = 0; k < n; ++k) {
                seqs.push_back(0);
            }
        }
        for (auto &item: seqs)item += 1;

        if (i + j < nums.size() && nums[i + j] > nums[i] + 1) {
            if (seqs.back() < 3)return false;
            seqs.clear();
        }
        i += j;
    }
    return seqs.back() >= 3;
}

int main() {
    cout << isPossible({1, 2, 3, 3, 4, 5}) << endl;
    cout << isPossible({1, 2, 3, 3, 4, 4, 5, 5}) << endl;
    cout << isPossible({1, 2, 3, 4, 4, 5}) << endl;
    cout << isPossible({1, 3, 3, 4, 4, 7, 8, 8, 9, 10}) << endl;
    cout << isPossible({1, 2, 3, 5, 6, 7}) << endl;
}
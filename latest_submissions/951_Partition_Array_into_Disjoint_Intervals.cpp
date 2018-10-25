class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
            int low = 0, high = A.size() - 1;
    int max = A[low];
    while (low < high) {
        if (A[high] >= max)high--;
        else {
            for (int i = low; i < high; ++i) {
                if (A[i] > max)
                    max = A[i];
            }
            low = high;
            high = A.size() - 1;
        }
    }
    return low + 1;
    }
};
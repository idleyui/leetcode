#include "alg.h"

int minDeletionSize(vector<string> A) {
    int n = A[0].size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < A.size(); ++j) {
            if (A[j][i] < A[j - 1][i]) {
                cnt += 1;
                break;
            }
        }
    }
    return cnt;
}

int main() {
    cout << minDeletionSize({"cba", "daf", "ghi"}) << endl;
    cout << minDeletionSize({"a", "b"}) << endl;
    cout << minDeletionSize({"zyx", "wvu", "tsr"}) << endl;
}
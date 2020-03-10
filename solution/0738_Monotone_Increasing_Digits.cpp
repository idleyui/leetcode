#include "alg.h"

int monotoneIncreasingDigits(int N) {
    if (N < 10) return N;
    string s = to_string(N);
    char low = s.back();
    int pos = s.size();
    for (int i = s.size() - 2; i >= 0; --i) {
        if (s[i] > low) {
            s[i] = s[i]-1;
            pos = i + 1;
        }
        low = s[i];
    }
    for (int j = pos; j < s.size(); ++j) {
        s[j] = '9';
    }
    return stoi(s);
}

int main() {
    vector<int> v = {101, 11, 10, 1234, 332};
    for (int i : v) {
        cout << i << "," << monotoneIncreasingDigits(i) << endl;
    }
}
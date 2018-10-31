#include "alg.h"

string countAndSay(int n) {
    string last = "1";
    for (int k = 0; k < n - 1; k++) {
        string new_str;
        for (int i = 0; i < last.size();) {
            int j = i;
            for (; j < last.size() && last[j] == last[i]; j++);
            int cnt = j - i;
            new_str += ('0' + cnt);
            new_str += last[i];
            i = j;
        }
        last = new_str;
    }
    return last;
}

int main() {
    for (int i = 0; i < 30; ++i) {
        cout << i + 1 << ":" << countAndSay(i + 1) << endl;
    }
    set<int> v{1,2,3};
}
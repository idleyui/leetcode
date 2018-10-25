#include "alg.h"
//todo

string decodeAtIndex(string S, int K) {
    vector<string> pieces;
    vector<int> repeat_time;
    int low = 0;
    int count = 0;
    for (int i = 0; i < S.size() && count < K; i++) {
        if (isdigit(S[i])) {
            if (low != i) {
                pieces.push_back(S.substr(low, i));
                repeat_time.push_back(S[i] - '0');
            }
            low = i + 1;
            count *= (S[i] - '0');
        } else {
            count++;
            if (count == K)return to_string(S[i]);
        }
    }
    for (int i = pieces.size() - 1; i >= 0; i--) {
        int basic = count / repeat_time[i];
        int pos = K % basic;
        if (pos > basic - pieces[i].size()) {
            return to_string(pieces[i][pos - (basic - pieces[i].size())]);
        } else {
            return to_string(pieces[i][pos ]);
        }
    }
}

int main() {
    vector<string> v{"leet2code3", "ha22", "a2345678999999999999999"};
    vector<int> vi{10, 5, 1};
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << vi[i] << ":" << decodeAtIndex(v[i], vi[i]) << endl;
    }
}
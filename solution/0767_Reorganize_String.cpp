#include "alg.h"

//vector<int> v(26,0);
//bool cmp(const char &c1, const char &c2) {
//    return v[c1 - 'a'] > v[c2 - 'a'];
//}

string reorganizeString(string S) {
    if (S.empty()) return "";
    vector<int> v(26, 0);
    for (char c: S)v[c - 'a']++;
    string result(S.size(), '0');
//    https://codereview.stackexchange.com/questions/173382/sorting-elements-according-to-frequency-of-occurence-in-c
    sort(S.begin(), S.end(), [&v](const char &c1, const char &c2) {
        return v[c1 - 'a'] > v[c2 - 'a'] || (v[c1 - 'a'] == v[c2 - 'a'] && c1 < c2);
    });
//    sort(S.begin(), S.end(), cmp);

    int j = 1, k = 0, i = 0;
    if (S.size() % 2 != 0 && S[0] == S[S.size() / 2]) {
        j = 0, k = 1;
    }
    for (; j < result.size(); j += 2, i += 1) {
        result[j] = S[i];
    }
    for (; k < result.size(); k += 2, i += 1) {
        if ((k > 0 ? result[k - 1] == S[i] : false) || (k<result.size()-1? result[k + 1] == S[i]:false)) { return ""; }
        result[k] = S[i];
    }
    return result;
}

int main() {
    vector<string> v = {"aab", "aaab", "acacdbd", "acacddd", "aaaabcd", "aaaaabcd"};
    for (auto s:v)
        cout << reorganizeString(s) << endl;
}
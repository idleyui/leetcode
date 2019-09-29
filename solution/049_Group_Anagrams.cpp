#include "alg.h"

string cnt_sort(string s) {
    int counter[26] = {0};
    for (char c: s)
        counter[c - 'a']++;
    string rt;
    for (int i = 0; i < 26; i++)
        rt += string(counter[i], i + 'a');
    return rt;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> s2v = {};
    for (string s: strs) {
//        string s1 = s;
//        sort(s1.begin(), s1.end());
        string s1 = cnt_sort(s);
        if (s2v.count(s1)) {
            s2v[s1].push_back(s);
        } else {
            s2v[s1] = {s};
        }
    }
    vector<vector<string>> rt = {};
    for (auto v: s2v)
        rt.push_back(v.second);
    return rt;
}

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto rt = groupAnagrams(input);
    for (auto v: rt) {
        print_container(v);
    }

}
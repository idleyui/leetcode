#include "alg.h"

// Solution 1: hashmap with counting sort
// https://leetcode.com/problems/group-anagrams/discuss/19200/C%2B%2B-unordered_map-and-counting-sort
string cnt_sort(string s) {
    int count[26] = {0};
    for (char c: s)
        count[c - 'a'] = 1;
    string ss;
    for (int i = 0; i < 26; i++)
        ss += string(count[i], 'a' + i);
    return ss;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> s2v = {};
    for (string s: strs) {
        string s1 = cnt_sort(s);
        s2v[s1].push_back(s);
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
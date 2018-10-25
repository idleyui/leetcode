class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
            int dic[26] = {0};
    for (string &s: B) {
        int tmp[26]={0};
        for (char c: s) tmp[c - 'a']++;
        for (int i = 0; i < 26; ++i) if (tmp[i] > dic[i])dic[i] = tmp[i];
    }

    vector<string> result;
    for (string &s:A) {
        int tmp[26]={0};
        for (char c:s) tmp[c - 'a']++;
        int i = 0;
        for (; i < 26 && tmp[i] >= dic[i]; ++i);
        if (i == 26)result.push_back(s);
    }
    return result;
    }
};
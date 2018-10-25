class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)return {};
        string arr[10]{"*", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> v={""};
        for (int i = 0; i < digits.size(); ++i) {
            string append = arr[digits[i] - '0'];
            vector<string> v1;
            // for (char c: append) {
                for (string s: v) {
                    for(char c: append)
                        v1.push_back(s+c)  ;      
                    // s.push_back(c);
                    // v1.push_back(s);
                }
            // }
            v = v1;
            // v.clear();
            // v.assign(v1.begin(), v1.end());
        }
        return v;
    }
};
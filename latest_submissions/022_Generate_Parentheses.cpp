class Solution {
public:
    void generateParenthesisRec(int n, int leftflow, string basic, set<string> &sset) {
        if (leftflow < 0)return;
        if (n == 0) {
            if (leftflow == 0) sset.insert(basic);
            return;
        }
        generateParenthesisRec(n - 1, leftflow + 1, basic + '(', sset);
        generateParenthesisRec(n - 1, leftflow - 1, basic + ')', sset);
    }
    
    vector<string> generateParenthesis(int n) {
        set<string> sset;
        generateParenthesisRec(n * 2, 0, "", sset);
        return vector<string>(sset.begin(), sset.end());
    }
};
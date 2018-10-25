class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<string> rows(min((int)s.length(), numRows));
        bool down = false;
        int i = 0;
        
        for(char c: s){
            rows[i] += c;
            if(i == 0 || i == numRows-1) down = !down;
            i += down?1:-1;
        }
        
        string rt;
        for(string s: rows) rt+=s;
        return rt;
    }
};
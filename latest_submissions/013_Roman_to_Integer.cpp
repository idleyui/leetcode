class Solution {
public:
    unordered_map<char, int> s2v{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                 {'C',100},{'D',500},{'M',1000}
                                };
    
    int romanToInt(string s) {
        int rt = 0;
        for(int i = 0; i < s.size(); i++){
            if(i < s.size()-1 && s2v[s[i+1]] > s2v[s[i]]){
                rt+=(s2v[s[i+1]] - s2v[s[i]]);
                i++;
            }else{
                rt+=s2v[s[i]];
            }
        }
        return rt;
    }
};
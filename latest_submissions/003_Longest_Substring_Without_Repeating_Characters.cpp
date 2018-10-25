class Solution {
public:
//     begin, max, v2p
    int lengthOfLongestSubstring(string s) {
        map<int, int> v2p{};
        int max = 0;
        for(int i = 0, begin = 0; i < s.length(); i++){
            int item = s[i];
            if(v2p.count(item)){
                begin = std::max(v2p[item] + 1, begin);
            }
            v2p[item] = i;
            max = std::max(max, i-begin+1);
        }
        return max;
    }
};
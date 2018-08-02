#include "alg.h"

int lengthOfLongestSubstring(string s) {
    map<int, int> s2p{};
    int max = 0, begin = 0;
    for(int i = 0; i < s.size(); i++){
        if(s2p.find(s[i]) != s2p.end()){
            int &p = s2p[s[i]];
            begin = begin > p?begin:(p+1);
        }
        s2p[s[i]] = i;
        max = (i-begin+1)>max?(i-begin+1):max;
    }
    return max;
}

int main() {
    cout << lengthOfLongestSubstring("abc");
}
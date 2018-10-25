class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        auto iter_s = s.begin();
        auto iter_t = t.begin();
        while(iter_s!=s.end())
        {
            if(*iter_s != *iter_t)
                return false;
            else
            {
                iter_s++;
                iter_t++;
            }
        }
        return true;
    }
};
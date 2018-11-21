class Solution {
public:
    string countAndSay(int n) {
        string last = "1";
        for(int k = 0; k < n-1; k++){
            string new_str;
            for(int i = 0; i < last.size();){
                int j = i;
                for(; j < last.size() && last[j] == last[i]; j++);
                int cnt = j - i;
                new_str += ('0'+cnt);
                new_str += last[i];
                i = j;
            }
            last = new_str;
        }
        return last;
    }
};
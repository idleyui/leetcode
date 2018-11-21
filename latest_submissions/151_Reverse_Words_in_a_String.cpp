class Solution {
public:
void remove_space(string &s) {
    int space_cnt = s.find_first_not_of(' ');
    if (space_cnt == s.npos) s = "";
    int word_cnt = 0;
    int span = 0;
    for (int i = space_cnt; i < s.size(); i++) {
        if (s[i] != ' ') {
            space_cnt += span;
            span = 0;
            word_cnt += 1;
            for (; i < s.size() && s[i] != ' '; i++) {
                int pos = i-space_cnt+word_cnt-1;
                if (pos != i){
                    s[pos] = s[i];
                    s[i] = ' ';
                }
            }
            if (i < s.size()) i--;
        } else {
            span++;
        }
    }
    space_cnt += span;
    s = s.substr(0, s.size() - space_cnt + word_cnt - 1);
}

void reverse(string &s, int start, int end){
    for (int i = start, j = end - 1; i < j; i++, j--)  swap(s[i], s[j]);
}

void reverseWords(string &s) {
    remove_space(s);
    reverse(s, 0, s.size());
    int pos = 0;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            reverse(s, pos, i);
            pos = i + 1;
        }
    }
    reverse(s, pos, s.size());
}

};
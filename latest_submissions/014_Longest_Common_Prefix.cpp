class Solution {
public:
    string longestCommonPrefix(vector<string>& list) {
        if(list.empty())return "";
        string result;
  for(int i = 0; i < list[0].size();i++){
    char c = list[0][i];
    for(string &s: list){
      if(s.size() <= i || s[i] != c){
        return result;
      }
    }
    result+=c;
  }
  return result;
    }
};
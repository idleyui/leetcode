class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        string left = "([{";
        string right = ")]}";
        
        for (char c: s) {
            if (left.find(c) != string::npos) {
                stack.push_back(c);
            } else if(!stack.empty()){
                char top = *(stack.end() - 1);
                if (top == left[right.find(c)]) stack.pop_back();
                else  return false;
            } else{
                return false;
            }
        }
        return stack.empty();
    }
};
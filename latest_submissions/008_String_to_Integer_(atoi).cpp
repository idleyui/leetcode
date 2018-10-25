class Solution {
public:
    int myAtoi(string str) {
        int i = str.find_first_not_of(' ');
        
        char sign = '+';
        if (str[i] == '-' || str[i] == '+') sign = str[i++];
        else if (!isdigit(str[i]))  return 0;
        
        int result = 0;
        for (int j = i; j < str.size() && isdigit(str[j]); j++) {
            int buf = result * 10 + (str[j] - '0');
            if (buf/10 != result)   return sign == '+' ? INT_MAX : INT_MIN;
            result = buf;
        }

        return sign == '+' ? result : -result;
    }
};
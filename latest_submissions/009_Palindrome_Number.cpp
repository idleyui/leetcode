class Solution {
public:
    bool isPalindrome(int num) {
        if(num < 0 || (num > 0 && num %10==0))return false;
  
        int result = 0;
        while(num > result){
            result = result * 10 + num %10;
            num /= 10;
        }
  
        return num == result || num*10 == result;
    }
};
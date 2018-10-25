
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while(x){
            int tmp = result*10 + x%10;
            if (tmp/10 != result)   return 0;
            result = tmp;
            x /= 10;
        }
        return result;
    }    
};
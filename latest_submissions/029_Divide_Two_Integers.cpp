class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT32_MIN && divisor == -1)return INT32_MAX;
        int reverse = dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0;
        dividend = dividend >= 0 ? -dividend : dividend;
        divisor = divisor >= 0 ? -divisor : divisor;
        int i = 0;
        while(dividend <= divisor){
            int base = divisor;
            int cnt = 1;
            while(true){
                int tmp = base + base;
                if (tmp < base && tmp >= dividend){
                    base = tmp;
                    cnt += cnt;
                } else{
                    break;
                }
            }
            dividend -= base;
            i += cnt;
        }
        return reverse ? -i : i;
    }
};
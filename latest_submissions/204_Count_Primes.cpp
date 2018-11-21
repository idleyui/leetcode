class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)  return 0;
        vector<int> isPrimes(n, 0);
        for(int i = 2; i <= n/2; i++){
            if (isPrimes[i])    continue;
            int base = i;
            while(base < n){
                base = base + i;
                if(base >= n || base < 0) break;
                isPrimes[base] = 1;
            }
        }
        return n - accumulate(isPrimes.begin(), isPrimes.end(), 0) - 2;
    }
};
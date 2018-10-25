class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = x ^ y;
        int label = 1;
        int count = 0;
        for(int i = 0; i < 31; i++){
            count += ((label & a) || 0);
            label = label << 1;
        }
        return count;
    }
};
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto iter = nums.begin();
        int count = 0;
        while(iter != nums.end())
        {
            if(*iter == 0)
            {
                iter = nums.erase(iter);
                ++count;
            }
            else
            {
                ++iter;
            }
        }
        for(int i =0;i<count;i++)
            nums.push_back(0);
    }
};
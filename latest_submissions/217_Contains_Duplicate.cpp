class Solution {
public:
    bool containsDuplicate(vector<int>& copy) {
        if(copy.size()<2)    return false;
        //vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        auto iter = copy.begin()+1;
        while(iter != copy.end())
        {
            if(*(iter-1)==*iter)
                return true;
            iter++;
        }
        return false;
    }
};
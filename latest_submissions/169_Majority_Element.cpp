class Solution {
public:
    int majorityElement(vector<int>& buf) {
        //vector<int> buf = nums;
        int size = buf.size();
        sort(buf.begin(), buf.end());
        if(size%2!=0)
            return buf[size/2];
        else
        {
            if(buf[size/2] == buf[size-1])
                return buf[size/2];
            return buf[size/2-1];
        }
    }
};
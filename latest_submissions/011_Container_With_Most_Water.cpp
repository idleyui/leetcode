class Solution {
public:
    int maxArea(vector<int>& height) {
//         left, right, max
        int left = 0, right = height.size()-1, m = 0;
        while(left < right){
            int tmp = min(height[left], height[right]) * (right-left);
            m = max(m, tmp);
            if (height[left] > height[right]) right--;
            else left++;
        }
        return m;
    }
};
class Solution {
public:
    double findMinK(vector<int>& nums1, vector<int>& nums2, int low1, int high1, int low2, int high2, int k){
        if (low1 > high1) return nums2[low2 + k - 1];
        if (low2 > high2) return nums1[low1 + k - 1];
        if (k == 1) return nums1[low1] < nums2[low2]?nums1[low1]:nums2[low2];
        int offset = k / 2;
        int left_i = (low1 + offset - 1)< high1?(low1 + offset - 1):high1, right_i=low2 + offset - 1;
        if (nums1[left_i] <= nums2[right_i]){
            return findMinK(nums1, nums2, left_i + 1, high1, low2, high2, k - (left_i-low1+1));
        }else if(nums1[left_i] > nums2[right_i]){
            return findMinK(nums1, nums2, low1, high1, right_i + 1, high2, k - offset);
        }
        // else{
            // if(k % 2 == 0){
                // return nums1[left_i];
            // }else{
                // return findMinK(nums1, nums2, left_i + 1, high1, right_i + 1, high2, 1);
            // }
        // }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int total = nums1.size() + nums2.size();
        int k = total / 2 + 1;
        
        if(total % 2 == 0){
            return (findMinK(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, k) + 
                    findMinK(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, k-1))/2;
        }else{
            return findMinK(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, k);
        }
    }
};
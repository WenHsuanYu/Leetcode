//TC: O(log(m + n))
//SC: O(log(m + n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        //little trick for generalization
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    //Find the value of kth element 
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size())
            return nums2[j + k - 1];
        if (j >= nums2.size()) 
            return nums1[i + k - 1];
        if (k == 1) 
            return min(nums1[i], nums2[j]);
        //Check if k/2th element is exist at index i + k / 2 - 1 
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2) {
            //drop them before index i + k /2 and subtract k/2 from k 
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            //same for nums2
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};


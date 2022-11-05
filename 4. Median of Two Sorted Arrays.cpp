// TC: O()
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int tmp = 0, tmp1 = 0;
        int index = 0;
        int i = 0, j = 0;
        
        if (m + n == 1) 
            return (m==0)? nums2[0]: nums1[0];
        
        while (i < m && j < n)
        {
            if (nums1[i] > nums2[j]) {
                tmp = tmp1;
                tmp1 = nums2[j];
                j++;
            } else {
                tmp = tmp1;
                tmp1 = nums1[i];
                i++;
            }
            if (index == (m + n) / 2) {
                if ((m + n) % 2)
                    return tmp1;
                else
                    return (tmp + tmp1) / 2.0;
            }
            index++;
            
        }
        
        while (i < m) {
            tmp = tmp1;
            tmp1 = nums1[i++];
            if (index == (m + n) / 2)
                break;
            index++;
        }
        while (j < n) {
            tmp = tmp1;
            tmp1 = nums2[j++];
            if (index == (m + n) / 2)
                break;
            index++;
        }
        
        return ((m + n) % 2) ? tmp1 : (tmp + tmp1) / 2.0;
    }
};
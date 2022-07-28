// Using two pointers - when elements to remove are rare
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                swap(nums[i], nums[n - 1]);
                n--;
            } else {
                i++;
            }
        }
        
        return n;
    }
};
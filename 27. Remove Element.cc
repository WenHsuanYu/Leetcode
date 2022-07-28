// Using two pointers
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int target = 0;
        int ptr = 0;
        
        for  (ptr = 0; ptr < nums.size(); ptr++) {
            if (nums[ptr] != val) {
                nums[target] = nums[ptr];
                // swap(nums[ptr], nums[target]);
                target++;
            }
        }
        
        return target;
    }
};
// TC: O(n)
// SC: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        // values in front of nums[NonZeroIndex] are nonzero.
        // Eventually NonZeroIndex points to the last nonzero index in the array 
        for (int NonZeroIndex = 0, i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[NonZeroIndex++], nums[i]);
            }
        }
        
    }
};
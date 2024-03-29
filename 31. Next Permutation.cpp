// TC: O(n)
// SC: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        int n = nums.size();
        int i = n -2, j = n -1;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0) {
            while (nums[j] <= nums[i])
                --j;
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
        reverse(nums.begin(), nums.end());
        
    }
};
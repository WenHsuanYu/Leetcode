// TC: O(n)
// SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 0;
        int duplicates = 1;
        int n = nums.size();
        for (duplicates; duplicates < n; duplicates++) {
            if (nums[unique] != nums[duplicates]) {
                nums[++unique] = nums[duplicates];
            }
        }
        //len 
        return unique + 1;
    }
};
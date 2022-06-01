//Follow up
//Divide and Conquer:
//TC: O(nlogn), SC(1)
class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        
        if (left > right)
            return INT_MIN;
        
        int mid = left + ((right - left) >> 1);
        int Leftside_ans = helper(nums, left, mid - 1);
        int Rightside_ans = helper(nums, mid + 1, right);
        
        int LeftSide_max = 0;
        int RightSide_max = 0;
        for (int i = mid - 1, sum = 0; i >= left; i--) {
            sum += nums[i];
            LeftSide_max = max(sum, LeftSide_max);
        }
        
        for (int i = mid + 1, sum = 0; i <= right; i++) {
            sum += nums[i];
            RightSide_max = max(sum, RightSide_max);
        }
        
        int sub_max = max(Leftside_ans, Rightside_ans);
        int curr_max = nums[mid] + LeftSide_max + RightSide_max;
        return curr_max > sub_max ? curr_max : sub_max;
        
    }
    
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
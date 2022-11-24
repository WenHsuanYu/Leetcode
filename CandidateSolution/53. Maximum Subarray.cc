class Solution {
public:
    int helper(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        int m = l + (r - l) / 2;
        int LeftMax = 0;
        int rightMax = 0;
        for (int i = m - 1, temp = 0; i >= l; i--) {
            temp += nums[i];
            LeftMax = max(LeftMax, temp);
        }
        for (int j = m + 1, temp = 0; j <= r; j++) {
            temp += nums[j];
            rightMax = max(rightMax, temp);
        }
        return max({helper(nums, l, m - 1), helper(nums, m + 1, r), LeftMax + nums[m] + rightMax});
    }
    
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
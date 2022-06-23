//using dp method
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int>dp(n, 0);
        //dp denotes that represents max value of robbery at index i and it could or could not contain nums[i].
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return dp[n - 1];
    }
};
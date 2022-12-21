// TC: O(n * (n + t) / 2)
// SC: O((n + t) / 2)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int newTarget = (target + sum) / 2;
        // if sum is less than target or numerator of newTarget is odd, then 
        // the result is impossible
        if (sum < target || (target + sum) & 1 || newTarget < 0) {
            return 0;
        }
        //if there is 1 element like nums[0] in array, then how many subarray we can make with target 
        vector<int> dp(newTarget + 1, 0);
        //empty subarray
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = newTarget; j >= nums[i]; j--) {
                    dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newTarget];
    }
};
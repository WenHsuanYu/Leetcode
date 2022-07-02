/*
* Using DP + offset 
* consider sum of nums will be negative, so, we let the minimum negative value plus the   * offset equals zero.
* TC: O(t * n), where t is the sum of `nums`
* SC: O(t * n)
*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int i: nums) {
            total += i;
        }
        vector<int>dp(2 * total + 1, 0);
        dp[nums[0] + total]++;
        dp[nums[0] * -1 + total]++;
        
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            vector<int> next(2 * total + 1, 0);
            for (int j = -1 * total; j <= total; j++) {
                if (dp.at(j + total) > 0) {
                    next.at(j - nums[i] + total) += dp.at(j + total);
                    next.at(j + nums[i] + total) += dp.at(j + total);
                }
            }
            dp = next;
        }
        
        return abs(target) > total ? 0 : dp[target + total];

    }
};
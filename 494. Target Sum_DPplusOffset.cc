/*
* Using DP + offset 
* Considering the range of j from -total to total, we need to add an offset to j to map to the only positive range.
* TC: O(t * n), where t is the sum of `nums`
* SC: O(t)
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
        dp[-nums[0] + total]++;
        
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            vector<int> next(2 * total + 1, 0);
            for (int j = -total; j <= total; j++) {
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
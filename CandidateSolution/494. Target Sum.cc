//TC: O(t * n), where t is the sum of the `nums` array and n refers to the length of the `nums` array.
//SC: O(t * n)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int offset = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * offset + 1, 0));
        dp[0][nums[0] + offset]++;
        dp[0][-nums[0] + offset]++;
        for (int i = 1; i < nums.size(); i++) {
            for (int sum = -offset; sum <= offset; sum++) {
                if (dp[i - 1][sum + offset] > 0) {
                    dp[i][sum + offset + nums[i]] += dp[i - 1][sum + offset];
                    dp[i][sum + offset - nums[i]] += dp[i - 1][sum + offset];
                }
            }
        }
        return abs(target) > offset ? 0 : dp[nums.size() - 1][target + offset];
    }
};
// TC: O(tn), where t is the sum of an `nums` array
// SC: O(t)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int target = sum >> 1;
        vector<int> dp(target + 1, 0);
        dp[0] = true;
        for (const auto& val : nums) {
            for (int i = target; i >= val; i--) {
                dp[i] = dp[i] || dp[i - val];
            }
        }
        return dp[target];
    }
};
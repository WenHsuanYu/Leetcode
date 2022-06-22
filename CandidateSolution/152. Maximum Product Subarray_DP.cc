// using DP method
// maintaining max_dp[n] which represents max product of subarray[i] ending with nums[i]
// maintaining min_dp[n] which represents min product of subarray[i] ending with nums[i]
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_dp(n, nums[0]);
        vector<int> min_dp(n, nums[0]);
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                max_dp[i] = max(nums[i], nums[i] * min_dp[i - 1]);
                min_dp[i] = min(nums[i], nums[i] * max_dp[i - 1]);
            } else {
                max_dp[i] = max(nums[i], nums[i] * max_dp[i - 1]);
                min_dp[i] = min(nums[i], nums[i] * min_dp[i - 1]);
            }
            ans = max(ans, max_dp[i]);
        }
        
        return ans;
    }
};
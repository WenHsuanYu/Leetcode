class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        sum >>= 1;
        vector<vector<int>> dp(len + 1, vector<int>(sum + 1, 0));
        for (int r = 0; r <= len; r++) {
            dp[r][0] = 1;
        }
        for (int r = 1; r <= len; r++) {
            for (int c = 1; c <= sum; c++) {
                //not pick number
                if (c < nums[r - 1]) {
                    dp[r][c] = dp[r - 1][c];
                }
                //can pick number if target is larger than or equal to nums[i - 1](number) 
                else {
                    dp[r][c] = dp[r][c] || dp[r - 1][c - nums[r - 1]]; 
                }
            }
        }
        return dp[len][sum];
    }
};
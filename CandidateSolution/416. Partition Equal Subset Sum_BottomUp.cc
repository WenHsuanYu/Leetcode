class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto &i : nums)
            sum += i;
        if (sum % 2 == 1) {
            return false;
        } 
        sum /= 2;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                //not pick number
                dp[i][j] = dp[i - 1][j];
                //can pick number if target is larger than or equal to nums[i - 1](number) 
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; 
            }
        }
        return dp[n][sum];
            
    }
};
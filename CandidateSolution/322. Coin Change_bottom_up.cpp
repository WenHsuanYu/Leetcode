class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1 << 30);
        dp[0] = 0;
        if (amount == 0)
            return 0;
        int len = coins.size();
        
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j + coins[i] <= amount; ++j) {
                dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
            }
        }
        
        return (dp[amount] == 1 << 30) ? -1 : dp[amount];
    }
};
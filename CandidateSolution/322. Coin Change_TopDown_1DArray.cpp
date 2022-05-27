//Top-down and 1D array method
class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1);
        for (auto &i : dp) {
            i = INT_MAX;
        }
        return recur(coins, amount);
    }
    
    int recur(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (dp[amount] == INT_MAX) {
            int minNum = INT_MAX;
            
            for (int i = 0; i < coins.size(); i++) {
                int num = -1;
                if (coins[i] <= amount) {
                    num = recur(coins, amount - coins[i]);
                }
                if (num >= 0 && num < minNum)
                    minNum = num + 1;
            }
            dp[amount] = (minNum == INT_MAX ? -1 : minNum);
        }
        
        return dp[amount];
    }
    
};
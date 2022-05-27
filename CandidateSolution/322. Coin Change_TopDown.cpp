//Top-down and 2d array
class Solution {
public:
    int dp[13][10001];
    int recur(vector<int> &coins, int amount, int n){
        
        if(dp[n][amount] != -1)
            return dp[n][amount];

        //base conditions
		if(amount == 0)
            return dp[n][amount] = 0;
		//you don't hae any coins representing coins of different denomination. so, it sets a random number.
		if(n == 0)
            return dp[n][amount] = INT_MAX >> 1;
        
        if(coins[n - 1] <= amount)
            return dp[n][amount] = min(1 + recur(coins, amount - coins[n - 1], n), recur(coins, amount, n - 1));
        else
            return dp[n][amount] = recur(coins, amount, n - 1);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        memset(dp, -1, sizeof(dp));
        
        int x = recur(coins, amount, coins.size()); 
        if(x == INT_MAX >> 1)
            return -1;
        return x;
    }
};
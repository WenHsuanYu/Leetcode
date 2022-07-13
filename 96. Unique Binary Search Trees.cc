//Using DP(bottom up) method
//TC: O(n^2)
//SC: O(n)

class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        
        return dp[n];
    }
};

/*
* class Solution {
* public:
*    vector<int>dp;
*     
*     int recur(int n) {
*         if (n == 0 || n == 1) {
*             return 1;
*         }
*         if (n == 2)
*             return 2;
*         if (dp[n] != 0) {
*             return dp[n];
*         }
*         int sum = 0;
*         for (int i = 1; i <= n; i++)
*             // i as a root computes a range [1, i - 1] possibilities as a left child tree
*             // i as a root computes a range [i + 1, n] possibilities as a right child tree
*             sum += (recur(i - 1) * recur(n - i));
*         dp[n] = sum;
*         return dp[n];
*     }
*     
*     
*     int numTrees(int n) {
*         dp.resize(n + 1, 0);
*         dp[0] = 1;
*         dp[n] = recur(n);
*         return dp[n];
*     }
* };
*/
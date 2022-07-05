//Using DP Bottom-up method
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/*
* class Solution {
* public:
*     int dp[46] = {0};
*     int climbStairs(int n) {
*         if (n == 1) {
*             return 1;
*         }
*         if (n == 2) {
*             return 2;
*         }
*         if (dp[n]) {
*             return dp[n];
*         }
*         
*         return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
*         
*     }
* };
*/
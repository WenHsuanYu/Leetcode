//TC: O(n)
//SC: O(1) (do not count result variable)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);    
        }
        return dp;
    }
};
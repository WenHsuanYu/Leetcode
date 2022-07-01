//Using DP method
//TC:O(nm)
//SC:O(n) 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[n + 1];
        for (int &i: dp) {
            i = 0;
        }
        for (int i = 1; i <= m; i++) {
            int prev = dp[0];
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = dp[j - 1] > dp[j] ? dp[j - 1] : dp[j]; 
                }
                prev = temp;
                   
            }
        }
        return dp[n];
    }
};
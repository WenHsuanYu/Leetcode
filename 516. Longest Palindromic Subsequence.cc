// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = len - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][len - 1];
    }
};


/*
* dp[i][j] 表示 [i, j] 中的字串的最長回文子序列
* s[i] = s[j] is true
* dp[i][j] = dp[i + 1][j - 1] + 2;
* s[i] = s[j] is false
* dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
*/
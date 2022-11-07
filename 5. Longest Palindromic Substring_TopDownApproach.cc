//Top-down DP
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        string ans = "";
        ans += s[0];
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                
                if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j -1])) {
                    dp[i][j] = true;
                    
                    if (ans.size() < j - i + 1) {
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        
        
        return ans;
    }
};
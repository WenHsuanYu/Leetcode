class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> >dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        // dp[i][j] 
        //case 1: i = 0, j = 0
        dp[0][0] = true;
        //case 2: i > 0, j = 0
        //dp[i > 0][j=0] = false;
        //case 3: i = 0, j > 0
        // s = "" p = "X*X*X*X*X*..."
        for (int j = 1; j <= p.length(); ++j) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }
        //case 4: i > 0, j > 0
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                int s_index = i - 1;
                int p_index = j - 1;
                if (p[p_index] == '.' || p[p_index] == s[s_index]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[p_index] == '*') {
                    dp[i][j] = dp[i][j - 2] || ((s[s_index] == p[p_index - 1] || p[p_index - 1] == '.') && dp[i - 1][j]);
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
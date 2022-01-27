class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        string ans = "";
        ans += s[0];
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            for (int j = i - 1; j >= 0; j--) {
                if (s[i] == s[j] && (i - j == 1 || dp[j + 1][i -1] == true)) {
                    dp[j][i] = true;
                    if (ans.size() < i - j + 1)
                        ans =  s.substr(j, i - j + 1);
                }
            }
        }
        
        return ans;
        
    }
};
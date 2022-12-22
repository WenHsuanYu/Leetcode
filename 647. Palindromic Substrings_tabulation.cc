// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        return tabulation(s);
    }
private:
    int tabulation(string& s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (j - i == 1) {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 0;
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};
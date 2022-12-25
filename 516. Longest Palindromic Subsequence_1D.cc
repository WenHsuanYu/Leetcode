// 1D dynamic programming
// TC: O(n^2)
// SC: O(n)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<int> dp(len, 1);
        for (int i = len - 1; i >= 0; i--) {
            int size = 0;
            for (int j = i + 1; j < len; j++) {
                int t = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = size + 2;
                }
                size = max(t, size);
            }
        }
        int ans = 0;
        for (const int& val : dp) {
            ans = max(ans, val);
        }
        return ans;

    }
};


/*
*   b b b a b
* b 1 2 3 1 4
* b   1 2 1 3
* b     1 1 3
* a       1 1
* b         1
*/

//Using Bottom-up DP method
//TC: O(nm)
//SC: O(n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
        }
        int prev;
        for (int i = 1; i <= m; i++) {
            prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (word1[i - 1] != word2[j - 1]) {
                    // int insertion = dp[j - 1];
                    // int deletion = dp[j];
                    // int replacement = prev;
                    dp[j] = min(prev, min(dp[j - 1], dp[j])) + 1;
                    
                } else {

                    dp[j] = prev;
                }

                prev = temp;
            }
        }
        
        return dp[n];
        
        
    }
};
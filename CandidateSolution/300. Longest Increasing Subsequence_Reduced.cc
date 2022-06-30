// LIS reduced to LCS and then solve LCS question
// O(nm)
// O(nm)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int>::iterator it = unique(sorted_nums.begin(), sorted_nums.end());
        sorted_nums.erase(it, sorted_nums.end());
        
        int ans = [&](){
            int n = nums.size();
            int m = sorted_nums.size();

            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (nums[i - 1] == sorted_nums[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];

                    } else {
                        dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                    }     
                }
            }
            
            return dp[n][m];
        }();
        return ans;
        
    }
};
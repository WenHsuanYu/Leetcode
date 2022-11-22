//TC: O(n^2)
//SC: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int len = nums.size();
        vector<int> dp(len, 1);
        int maxL = 1;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] < nums[j]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    maxL = maxL > dp[j] ? maxL : dp[j];
                }
            }
        }
        
        return maxL;
    }
};
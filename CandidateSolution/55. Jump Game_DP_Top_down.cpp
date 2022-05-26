class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        //dp denotes whether you can reach the end from the index i or not
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            //Consider steps from 1 to nums[i]
            for (int j = 1; j <= nums[i]; j++) {
                if (dp[j + i]) {
                    dp[i] = true;
                    break;
                }
            }
        }
    
        return dp[0];
    }
};
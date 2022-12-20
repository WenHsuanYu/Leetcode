// TC: O(nlogn)
// SC: O(1), where does not include output variable. 
class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num != 0) {
                sum += (num & 1);
                num >>= 1;
            }
            dp[i] = sum;
        }
        return dp;
    }
};
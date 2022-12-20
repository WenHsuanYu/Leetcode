// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            //dp[i] = bitset<32>(i).count();
            dp[i] = __builtin_popcount(i);
        }
        return dp;
    }
};
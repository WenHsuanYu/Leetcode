static auto last = []{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        //dp[i]: denotes that the minimum number of jumps from index 0 to index i
        vector<int> dp(n, 10000);
        
        dp[0] = 0;
        //Bottom-up approach
        //traverse backward
        for (int i = 0; i < n - 1; ++i) {
            for (int j = nums[i]; j > 0; --j) {
                    (i + j <= n -1) ? dp[i + j] = min(dp[i + j], dp[i] + 1) : 0;
                
            }
        }
        
        return dp[n -1];
    }
};
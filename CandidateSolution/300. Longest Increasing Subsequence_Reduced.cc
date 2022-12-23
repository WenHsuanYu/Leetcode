// LIS reduced to LCS and then solve LCS question
// O(nm)
// O(m)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        auto it = unique(sorted_nums.begin(), sorted_nums.end());
        sorted_nums.erase(it, sorted_nums.end());

        auto ans = [&]() {
            int n = nums.size();
            int m = sorted_nums.size();
            vector<int> dp(m + 1, 0);
            for (int i = 1; i <= n; i++) {
                int prev = dp[0];
                for (int j = 1; j <= m; j++) {
                    int tmp = dp[j];
                    if (nums[i - 1] == sorted_nums[j - 1]) {
                        dp[j] = prev + 1;
                    } else {
                        dp[j] = max(dp[j], dp[j - 1]);
                    }
                    prev = tmp;
                }
                cout << endl;
            }
            return dp[m];
        }();
        return ans;
    }
};
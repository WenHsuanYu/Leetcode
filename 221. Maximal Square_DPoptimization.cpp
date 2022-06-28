//Using DP method for better space utilization
//TC: O(mn)
//TC: O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int max_edge = 0;
        int prev = 0;
        vector<int> dp(col + 1, 0);
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                    max_edge = max(max_edge, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        for (auto i: dp)
            cout << i << " ";
        return max_edge * max_edge;
    }
};
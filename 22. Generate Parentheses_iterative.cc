// Using iterative DP method
// important equation: Cn = C0Cn-1 + C1Cn-2 + ... + Cn-1C0
//TC: O(4^n / (n * sqrt(n)))
//SC: O(4^n / (n * sqrt(n)))
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (auto& left : dp[j]) {
                    for (auto& right: dp[i - 1 - j]) {
                        dp[i].push_back('(' + left + ')' + right);
                    }
                }
            }
        }
        return dp[n];
    }
};

// left: ""
// i = 1
// j = 0
// dp[1].push_back(());
// dp[0] = {""};
// dp[1] = { "()" };
// i = 2
// j = 0
// left = ""
// right = "()"
// dp[2].push_back("()()")
// i = 2
// j = 1
// left: "()"
// right: ""
// dp[2].push_back("(())")
// dp[2] = {"(())", "()()"};
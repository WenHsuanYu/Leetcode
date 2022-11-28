// Using DP + Backtracking method
//TC: O(n * 2^n)
//SC: O(n * n)
class Solution {
public:
    vector<string> curr;
    vector<vector<string>> ans;
    
    void dfs(string& s, vector<vector<bool>>& dp, int start) {
        if (start >= s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int end = start; end < s.size(); end++) {
                                    //string length <= 3 || >=4
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                curr.push_back(s.substr(start, end - start + 1));
                dfs(s, dp, end + 1);
                curr.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        int len = s.length();
    
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        dfs(s, dp, 0);
        return ans;
    }
};
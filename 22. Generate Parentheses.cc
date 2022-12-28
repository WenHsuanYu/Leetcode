//Using backtrack
//TC: O(4^n / (n * sqrt(n)))
//SC: O(n)
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string tmp = "";
        dfs(0, 0, n, tmp);
        return ans;
    }
private:
    void dfs(int open, int close, int& n, string tmp) {
        if (close == n) {
            ans.push_back(tmp);
            return;
        }
        
        if (open < n) {
            dfs(open + 1, close, n, tmp + "(");
        }
        if (close < open) {
            dfs(open, close + 1, n, tmp + ")");
        }
        
    }
};
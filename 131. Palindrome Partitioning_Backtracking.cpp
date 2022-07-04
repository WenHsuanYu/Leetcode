// Using Backtracking method
// TC: O(n * 2^n)
// SC: O(n)
class Solution {
public:
    bool isPali(int start, int end, string& s) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
            
        }
        return true;
    }
    
    void dfs(vector<vector<string>>& ans, vector<string>& curr, string& s, int start) {
        if (start == s.size()) {
            ans.push_back(curr);
            return; 
        }
        for (int end = start; end < s.size(); end++) {
            if (isPali(start, end, s)) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(ans, curr, s, end + 1);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(ans, curr, s, 0);
        return ans;
    }
};
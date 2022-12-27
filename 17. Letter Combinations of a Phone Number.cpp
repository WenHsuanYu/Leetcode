// TC: O(4^n)
// SC: O(n)
class Solution {
public:
    vector<string> res;
    
    void dfs(int idx, string& digits, unordered_map<int, string>& m, string& ans) {
        if(idx == digits.length()){
            res.push_back(ans);
            return;
        }
        int curr = digits[idx] - '0';
        string op = m[curr];
        
        for (int i = 0; i < op.length(); i++) {
            ans.push_back(op[i]);
            dfs(idx + 1, digits, m, ans);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        unordered_map<int, string> map = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        string ans = "";
        dfs(0, digits, map, ans);
        return res;
    }
};
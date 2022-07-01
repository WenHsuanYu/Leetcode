//Using backtrack
//TC: O(4^n / (n * sqrt(n)))
//SC: O(4^n / (n * sqrt(n)))
class Solution {
public:
    int len;
    vector<string> ans;
    void backtrack(int n, int open, int close, string temp) {
        if (temp.size() == len) {
            ans.push_back(temp);
            return;
        }
        
        if (close < open) {
            backtrack(n, open, close + 1, temp + ")");
        }
        
        if (open < n) {
            backtrack(n, open + 1, close, temp + "(");
            
        }
        // if (close < open) {
        //     backtrack(n, open, close + 1, temp + ")");
        // }
    }
    
    vector<string> generateParenthesis(int n) {
        len = n << 1;
        backtrack(n, 0, 0, "");
        return ans;
        
    }
};
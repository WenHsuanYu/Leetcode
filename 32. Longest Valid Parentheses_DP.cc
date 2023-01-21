// TC: O(n)
// SC: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int res = 0;
        vector<int> dp(len, 0);
        for (int i = 1; i < len; i++) {
            if (s[i] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                int last = i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0;
                dp[i] = last + dp[i - 1] + 2;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


// dp[i]: means the length of the longest valid parentheses ends at index i
// if s[i] == ')' and s[i-1] == '(' → dp[i] = dp[i-2] + 2 = dp[i - 1] + 2
// if s[i] == ')' and s[i-1] == ')' and s[i-dp[i-1]-1] == '(' 
//   then dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]
// for example  ..... ...........     (      ( (  )  )     )
//                               i-dp[i-1]-1        i - 1   i
// when index is at i - 1, valid parentheses may be constranited by open parenthesis such that it can not lengthen. however, if s[i] equals to ), then valid parentheses can lengthen, so we need to consider i - dp[i - 1] - 2 (the value of dp)  
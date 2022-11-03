//TC: O(n), where n is the length of string
//SC: O(n)
class Solution {
public:
    //non-empty string
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int len = s.length();
        //dp[i] means ways can decode from s[0] to s[i - 1]
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = 1; 
        for (int i = 2; i <= len; i++) {
            //consider when s[i - 1] equals to zero, what happen?
            // for example 2: it have (2)(2)(6) (22),(6) two ways
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                //(2)(26)
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
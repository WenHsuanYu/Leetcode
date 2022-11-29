//Using DP method
//TC: O(n^2)
//SC: O(n)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[i] means 0...i can be separated by words in wordDict
        vector<bool> dp(s.size() + 1, false);
        /*
        *    l e e t c o d e
        *  0 1 2 3 4 5 6 7 8
        */
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                if (i >= wordDict[j].size() && wordDict[j] == s.substr(i - wordDict[j].size(), wordDict[j].size()) && dp[i - wordDict[j].size()]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
        
        
    }
};
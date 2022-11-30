//Using DP method
//TC: O(n^2)
//SC: O(n)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[i] means 0...i can be separated by words in wordDict
        int len = s.size();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        /*
        *    l e e t c o d e
        *  0 1 2 3 4 5 6 7 8
        */
        
        int lenDict = wordDict.size();
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < lenDict; j++) {
                int lenWord = wordDict[j].size();
                if (i >= lenWord && wordDict[j] == s.substr(i - lenWord, lenWord) && dp[i - lenWord]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
        
        
    }
};
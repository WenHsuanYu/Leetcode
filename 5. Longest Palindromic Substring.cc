// Manacher's algorithm (馬拉車演算法)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int n = 2 * len + 1;
        vector<int> dp(n);
         // the position of current center
        int C = 1;
        //The right border position (included) of the current center in the palindrome
        int R = 1;
        //for record
        int maxIndex = 0;
        int maxLen = 0;
        for (int i = 1; i < n; i++) {
            int mirrorI = C - (i - C);
            int gap = R - i;
            if (gap > 0) {
                dp[i] = min(dp.at(mirrorI), gap);
            }
            
        
            //Although the index value ranges from 0 to n-1, the dp value must be valid in the end, 
            //so i - dp[i] must stop at 0 and i + dp[i] must stop at n - 1 
            while ((i - dp.at(i) > 0) && (i + dp.at(i) < n - 1) && \
                  (((i + dp.at(i) + 1) % 2 == 0) || (s[(i+dp.at(i)+1)/2] == s[(i-dp.at(i)-1) / 2]))) {
                dp.at(i)++;
            }
            //Update maxLen if true
            if (dp.at(i) > maxLen) {
                maxLen = dp.at(i);
                maxIndex = i;
            }
            //Update radius if true
            if (i + dp.at(i) > R) {
                C = i;
                R = i + dp.at(i);
            }
        }
        
        
        int index = (maxIndex - maxLen) / 2;
        return s.substr(index, maxLen);
        
    }
};
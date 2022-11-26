//TC: O(n), where n is the length of string
//SC: O(n)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // dp[i] means the # of ways to decode from 0...i
        vector<int> dp(n, 0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] > '0') {
                dp[i] += i ? dp[i-1] : 1;
            }
            if (i && (s[i-1] == '1' || s[i-1] == '2' && '0' <= s[i] && s[i] <= '6')) {
                dp[i] += i > 1 ? dp[i-2] : 1;
            }
        }
        return dp.back();
    }
};

//     i:0123
// value:2214
// dp[i]:1235
/* 因為 14 可以發現是介於10到26之間（含兩側），在 dp[1] 的情況下，可以加入14，所以會有額外兩組解 
 * 22 14
 * 2, 2, 14
 */
/* 在dp[3]，對應到 string 值為 4，發現不是零，所以可以直接單獨加入dp[2] 各種解
 * 2, 2, 1, 4    
 * 2, 21, 4
 * 22, 1, 4
*/
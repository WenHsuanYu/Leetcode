//Using middle-out method
//TC: O(n^2)
//SC: O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        //every single char in string s
        int res = len;
        //odd 
        for (int i = 1, l = 0, r = 2; i < len; i++, l = i - 1, r = i + 1) {
            while (l >= 0 && r < len && s[l] == s[r]) {
                l--;
                r++;
                res++;
            }
        }
        //even
        for (int i = 1, l = 0, r = 1; i < len; i++, l = i - 1, r = i) {
            while (l >= 0 && r < len && s[l] == s[r]) {
                l--;
                r++;
                res++;
            }
        }
        return res;
        
    }
};
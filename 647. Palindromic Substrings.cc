//Using middle-out method
//TC: O(n^2)
//SC: O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        //every single char in string s
        int res = len;
        int l = 0;
        int r = 2;
        //odd 
        for (int i = 1; i < len; i++, l = i - 1, r = i + 1) {
            while (l >= 0 && r < len && s[l] == s[r]) {
                l--;
                r++;
                res++;
            }
        }
        //even
        l = 0;
        r = 1;
        for (int i = 1; i < len; i++, l = i - 1, r = i) {
            while (l >= 0 && r < len && s[l] == s[r]) {
                l--;
                r++;
                res++;
            }
        }
        return res;
        
    }
};
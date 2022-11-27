//TC:O(N)
//SC:O(1)
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        int last1 = 1;
        int last2 = 1;
        //We can use last1 and last2 to perform constant space dp since dp depends only on
        //last two values  
        for (int i = 0; i < len; i++) {
            int tmp = 0;
            if (s[i] > '0') {
                tmp += last1;
            }
            if (i && (s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                tmp += last2;
            }
            last2 = last1;
            last1 = tmp;
        }
        return last1;
    }
};

// Using KMP algorithm
// TC: O(m + n)
// SC: O(m)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int len = needle.size();
        vector<int> table(len, 0);
        int partial = 1;
        int whole = 0;
        // build table
        while (partial < len) {
            if (needle[partial] == needle[whole]) {
                partial++;
                whole++;
                table[partial - 1] = whole;
            } else if(whole == 0) { // compard to first prefix in `needle`
                table[partial] = 0;
                partial++;
            } else {
                whole = table[whole - 1];
            }
        }
        int index_n = 0;
        int index_h = 0;
        int len_h = haystack.length();
        // search for pattern string 'needle'
        while (index_h < len_h) {
            if (haystack[index_h] == needle[index_n]) {
                index_h++;
                index_n++;
            // each other not equals, so consider how much distance does it need to move right
            } else if (index_n) {
                index_n = table[index_n - 1];
            } else {
                index_h++;
            }
            
            if (index_n == len) {
                return index_h - index_n;
            }
            
        }
        
        
        
        
        return -1;
        
    }
};
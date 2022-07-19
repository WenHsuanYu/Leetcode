//TC: O(n*m)
//SC: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        int hlen = haystack.size();
        int nlen = needle.size();
        for(int i = 0; i <= hlen - nlen; i++) {
            if(haystack.substr(i, nlen) == needle)
                return i;
        }
        return -1;
    }
};
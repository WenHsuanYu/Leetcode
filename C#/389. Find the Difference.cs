// TC: O(m+n)
// SC: O(1)
public class Solution {
    public char FindTheDifference(string s, string t) {
        char res = (char)0;
        foreach (char c in s + t) 
            res ^= c;
        return res;
    }
}
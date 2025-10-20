// 409. Longest Palindrome
// TC: O(N) where N = s.length()
// SC: O(1) since the size of the map is fixed

class Solution {
    public int longestPalindrome(String s) {
        int[] map = new int[128];
        for (char c : s.toCharArray()) map[c]++;
        
        int pairs = 0;
        for (int count : map) pairs += count / 2;
        
        return pairs * 2 + (pairs * 2 < s.length() ? 1 : 0);

    }
}

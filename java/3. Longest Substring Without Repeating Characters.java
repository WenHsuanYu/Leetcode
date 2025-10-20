// 3. Longest Substring Without Repeating Characters
// TC: O(N) where N = s.length()
// SC: O(1) since the pos array size is fixed

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int max_len = 0;
        int[] pos = new int[255];

        Arrays.fill(pos, -1);

        for (int right = 0; right < s.length(); right++) {
            if (pos[s.charAt(right)] != -1) {
                left = Math.max(pos[s.charAt(right)] + 1, left);
            }
            pos[s.charAt(right)] = right;
            int len = right - left + 1;
            max_len = (max_len > len) ? max_len : len;
        }
        return max_len;
    }
}
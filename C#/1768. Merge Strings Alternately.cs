// TC: O(max(word1Len, word2Len))
// SC: O(1)
public class Solution {
    public string MergeAlternately(string word1, string word2) {
        StringBuilder result = new StringBuilder();
        int word1Len = word1.Length;
        int word2Len = word2.Length;
        int i = 0;
        int j = 0;

        while (i < word1Len || j < word2Len)
        {
            if (i < word1Len)
            {
                result.Append(word1[i++]);
            }
            if (j < word2Len)
            {
                result.Append(word2[j++]);
            }
        }

        return result.ToString();
    }
}
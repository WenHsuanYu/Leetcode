class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> table(255, -1);
    
        int right = 0;
        int left = 0;
        int curr_len = 0;
        int max_len = 0;
        while (right < s.size()) {
            
            if (table[s[right]] != -1) 
                left = max(table[s[right]] + 1, left);
            
            table[s[right]] = right;
            
            curr_len = right - left + 1;
            max_len = max(curr_len, max_len);
            
            right++;
        }
        
        return  max_len;
    }
};
//Using table method
//TC: O(n)
//SC: O(m)
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

/* Using Hash table method */
//TC: O(n)
//SC: O(min(m,n))
/*
* class Solution {
* public:
*     int lengthOfLongestSubstring(string s) {
*         unordered_map<char, int> umap;
*         
*         int right = 0;
*         int left = 0;
*         int res = 0;
*         int n = s.length();
*         for(right; right < n; right++) {
*             if (umap.find(s[right]) != umap.end()) {
*                 left = umap[s[right]] > left ? umap[s[right]] : left;
*             }
*             int len = right - left + 1;
*             res = res > len ? res : len;
*             umap[s[right]] = right + 1;
*             
*         }
*         return res;
*     }
* };
**/
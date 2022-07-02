//Using hash table method
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       
        int len = s.size();
        int len_p = p.size();
        vector<int> schar(26, 0);
        vector<int> pchar(26, 0);
        
        vector<int> ans;
        int right = 0;
        int left = 0;

        if(len < len_p) {
            return ans;
        }
        
        while (right < len_p) {
            pchar[p[right] - 'a']++;
            schar[s[right]- 'a']++;
            right++;
        }
        right -= 1;
        
        while (right < len) {
            
            if (pchar == schar) {
                ans.push_back(left);
            }
            
            right += 1;
            if (right != len) {
                schar[s[right] - 'a']++;
                
            }
            schar[s[left] - 'a']--;;
            left++;
        }
        
        return ans;
    }
};
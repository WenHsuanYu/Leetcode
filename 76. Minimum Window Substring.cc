//Using sliding window method
//TC: O(n + m)
//SC: O(m)
class Solution {
public:
    string minWindow(string s, string t) {
        //ascii code
        //vector<int> map(128, 0);
        unordered_map<int, int> m;
        for (auto ch: t) {
            m[ch]++;
        }
        int counter = t.size();
        int left = 0;
        int right = 0;
        int d = INT_MAX;
        int start = 0;
        while (right < s.size()) {
            if (m[s[right++]]-- > 0) {
                counter--;
            }
            //if not use increment or decrement, then add code below
            //m[s[right]]--;
            //right++;
            while (counter == 0) {
                if (right - left < d) {
                    d = right - (start = left);
                }
                
                if (m[s[left++]]++ == 0) {
                    counter++;
                }
                //m[s[left]]++;
                //left++;
            }
            
            
        }
        
        return d == INT_MAX ? "" : s.substr(start, d);
        
    }
};
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, uint32_t> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        int ans = 0;
        int len = s.length();
        ans += map[s[0]];
        for (int i = 1; i < len; i++) {
            if (map[s[i - 1]] < map[s[i]]) {
                ans += -2 * map[s[i - 1]] + map[s[i]];
            } else {
                ans += map[s[i]];
            }
        }
        
        
        return ans;
    }
};
// Using recursion method
// TC: O(n)
// SC: O(1)
class Solution {
public:
    
    string decode(string s, int &pos) {
        int n = s.size();
        string ans = "";
        int num = 0;
        for (; pos < n; pos++) {
            //isalpha(s[pos])
            if (s[pos] >= 'a' && s[pos] <= 'z') {
                ans += s[pos];
            //isdigit(s[pos])
            } else if (s[pos] >= '0' && s[pos] <= '9') {
                num = num * 10 + s[pos] - '0';
            } else if (s[pos] == ']') {
                return ans;
            } else {
                string temp = decode(s, ++pos);
                while (num) {
                    ans += temp;
                    num--;
                }
            }
        }
        
        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return decode(s , i);
    }
};
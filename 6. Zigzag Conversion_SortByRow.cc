// Sort by Row
// TC: O(n)
// SC: O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> str(min((int)s.size(), numRows));
        int index = 0;
        bool flag = false;
        for (char c: s) {
            str[index] += c;
            if (index == 0 || index == numRows - 1)
                flag = !flag;
            index += flag ? 1 : -1;
        }
        string res = "";
        for (auto s: str) {
            res += s;
        }
        return res;
        
    }
};
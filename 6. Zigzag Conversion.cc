// Visit by row
// TC: O(n)
// SC: O(1)

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        string str = "";
        int n = s.size();
        int cycleLen = 2 * numRows - 2; 
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                str += s[i + j];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    str += s[j + cycleLen - i];
                }
            }
        }
        return str;
        
    }
};
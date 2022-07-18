// TC: O(nm), where m is the length of strs[0]
// SC: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (strs[0] == "")
            return "";
        string prefix = strs[0];
        int index = 0;
        while (index < prefix.size()) {
            for (int i = 1; i < n; i++) {
                int len = strs[i].size();
                if (len >= index && prefix[index] != strs[i][index]) {
                    return prefix.substr(0, index);
                }
            }
            index++;
        }
        
        return prefix;
    }
};
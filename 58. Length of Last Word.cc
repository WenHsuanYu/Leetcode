//TC: O(n), where n is the length of the string s
//SC: O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        auto it = s.rbegin();
        while (it != s.rend()) {
            if (*it == ' '){
                it++;
                continue;
            } else {
                break;
            }
        }
        while (it != s.rend()) {
            if (*it != ' ') {
                len++;
                it++;
            } else {
                break;
            }
        }
        return len;
    }
};
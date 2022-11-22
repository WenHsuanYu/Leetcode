// TC: O(n)
// SC: O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            swap(s[head++], s[tail--]);
        }
    }
};
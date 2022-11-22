// TC: O(kn)
// SC: O(1)
class Solution {
public:
    string reverseStr(string s, int k) {
        
        for (int head = 0; head < s.length(); head += 2 * k) {
            int i = head;
            int j = min(head + k - 1, (int)(s.length() - 1));
            while (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
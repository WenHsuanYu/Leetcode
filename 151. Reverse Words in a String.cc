//TC: O(n)
//SC: O(k), where k is the number of words
class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        int prev = 0;
        int next = 0;
        //O(n)
        while (next < s.size()) {
            if (s[next] == ' ') {
                next++;
                continue;
            }
            prev = next;
            while (next < s.size() && s[next] != ' ') {
                next++;
            }
            res.push_back(s.substr(prev, next - prev));
            prev = next;
        }
        string ans = "";
        for (int i = res.size() - 1; i >= 0; i--) {
            ans += res[i] + " ";
        }
        ans.pop_back();
        return ans;
    } 
};
//Using stack method
//TC: O(n)
//SC: O(n)
class Solution {
public:
    string decodeString(string s) {
        string cstr = "";
        vector<pair<string, int>> st;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                st.push_back({cstr, sum});
                sum = 0;
                cstr = "";
            } else if (s[i] == ']') {
                sum = st.back().second;
                auto tmp = cstr;
                cstr = st.back().first;
                while (sum) {
                    cstr += tmp;
                    sum--;
                }
                st.pop_back();
            } else if (isdigit(s[i])) {
                sum = 10 * sum + (s[i] - '0');
            } else {
                cstr += s[i];
            }
        }
        return cstr;
    }
};
//Using stack method
//TC: O(n)
//SC: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else if (!st.empty()) {
                if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' and st.top() == '[') ||
                   (s[i] == '}' and st.top() == '{' ))
                    st.pop();
                else {
                    return false;
                }
            } else {
                return false;
            }
                
        }
        return st.empty();
    }
};
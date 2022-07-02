//Using stack method
//TC: O(n)
//SC: O(n)
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if ( s[i] != ']') {
                st.push(s[i]);
            } else {
                string curr = "";
                
                while (st.top() != '[') {
                    curr = st.top() + curr;
                    st.pop();
                }
                st.pop();
                
                string number;
                
                while (!st.empty() && st.top() <= '9') {
                    number = st.top() + number;
                    st.pop();
                }
                int count = stoi(number);
                int len_curr = curr.length();
                while (count--) {
                    for (int i = 0; i < len_curr; i++) {
                        st.push(curr[i]);
                    }
                }
                
            }

        }
        
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
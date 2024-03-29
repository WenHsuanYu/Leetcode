//Using stack method
//TC: O(n)
//SC: O(n) (It happend to the string s only has '(')
class Solution {
public:
    int longestValidParentheses(string s) {
        ios::sync_with_stdio(false);
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                //stack always have a base index which can not form a valid parenthesis as the bases for computing the length of valid parentheses.
                st.pop();
                //Update the bases
                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
                 
        }
        
        return ans;
    }
};
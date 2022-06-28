//Using Stack method
//TC: O(n)
//SC: O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios::sync_with_stdio(false);
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }
            st.push(i);         
        }
        
        return ans;
    }
};
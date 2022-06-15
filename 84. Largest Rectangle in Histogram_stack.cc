//using stack method
//TC:O(n)
//SC:O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //create a stack of type int, called st
        stack<int> st;
        int max_area = 0;
        // i = n means computes an area at the last index of heights.
        // i is also treated as the right boundary
        for (int i = 0; i <= n; i++) {
            int curr_height = i == n ? 0 : heights[i];
            
            while (!st.empty() && curr_height < heights[st.top()]) {
                int top = st.top();
                st.pop();
                // width have two possibilities
                //first:
                //The stack is empty and it means that all heights in front of heights[i] are greater than height[i].
                //second:
                //The stack is not empty and the top of stack is treated as the left boundary.
                int width = st.empty() ? i : i - st.top() - 1;
                int area = heights[top] * width;
                max_area = max(max_area, area);
            }
            
            st.push(i);
        }
        
        return max_area;
    }
};
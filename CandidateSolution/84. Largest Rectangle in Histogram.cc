//using two pointers 
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
            return 0;
        int maxArea = 0;
        
        //boundary
        vector<int> left(n);
        vector<int> right(n);

        
        left[0] = -1;
        right[n - 1] = n;
        // go to the left from index i
        //TC: O(n - 2 + k) ~ O(n), where k is the total amount of number of executions in "while" minus n - 2.
        for (int i = 1; i < n; i++) {
            int l = i - 1;
            //execute a constant number of times (maybe zero, once, twice, but not too much) during every index i 
            while(l >= 0 && heights[l] >= heights[i]) {
                l = left[l];
            }
            left[i] = l;
        }
        
        // go to the right from index i
        for (int i = n -2; i >= 0; --i) {
            int r = i + 1;
            while (r <= n - 1 && heights[r] >= heights[i]) {
                r = right[r];
            }
            right[i] = r;
        }
        
        
        for (int i = 0; i < n; i++) {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
        
        
    }
};
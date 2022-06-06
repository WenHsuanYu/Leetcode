// Using stack data structure to solve
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> s;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {

            while (!s.empty() && height[s.top()] < height[i]) {
                int top = s.top();
                s.pop();
                
                if (s.empty())
                    break;
                
                int w = i - s.top() - 1;
                int h = min(height[i], height[s.top()]) - height[top];
                ans += w * h;
                
            }
            
            s.push(i);
            
        }
        
        return ans;
        
    }
};
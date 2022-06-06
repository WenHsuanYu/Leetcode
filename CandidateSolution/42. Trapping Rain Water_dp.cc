//Sol:
//first: looking from left to right and computing the maximum capacity
//second: looking from right to left and find the minimum between the first-step computing and this computing.
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int dp[n];
        int currMax = -1;
        int ans = 0;
        
        for (int i = 0, h; i < n; ++i) {
            h = height[i];
            currMax = max(currMax, h);
            dp[i] = currMax - h;
        }        
        
        currMax = -1;
        
        for (int i = n - 1, h; i >= 0; --i) {
            h = height[i];
            currMax = max(currMax, h);
            ans += min(dp[i], currMax - h);
        }
        
        return ans;
    }
};
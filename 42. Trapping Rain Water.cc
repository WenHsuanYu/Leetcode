// TC: O(n)
// SC: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxL = height[i];
        int maxR = height[j];
        int res = 0;
        int h;
        
        while (i < j) {
            if (height[i] > height[j]) {
                h = height[j];
                if (h > maxR) {
                    maxR = h;
                } else {
                    res += maxR - h;
                }
                j--;
            } else {
                h = height[i];
                if (h > maxL) {
                    maxL = h;
                } else {
                    res += maxL - h;
                    
                }
                i++;
            }
        
        }
        
        return res;
    }
};
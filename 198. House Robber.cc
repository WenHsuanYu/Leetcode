//using dp concept without memorization 
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int next = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                prev = max(prev + nums[i], next);
            } else {
                next = max(next + nums[i], prev);
            }
        }
        return max(prev, next);
    }
};
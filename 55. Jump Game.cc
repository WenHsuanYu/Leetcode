// Greedy algorithm
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int curr_max = nums[0];
        int next_max = nums[0];
        for (int i = 0; i < len; i++) {
            next_max = max(next_max, i + nums[i]);
            
            if (i > curr_max) {
                //stuck on a certain index
                return false;
            } else if (i == curr_max) {
                curr_max = next_max;
            }
            
        }
        return true;
    }
};
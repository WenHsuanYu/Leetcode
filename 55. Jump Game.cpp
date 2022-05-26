// Greedy algorithm
// starting from index i equals to 0 and ending with index i equals to last element. (Bottom-up)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int len = nums.size();
        
        int steps = 0;
        
        for (int i = 0; i < len; i++)
        {
            //It can't reach index i.
            if (i > steps)
                break;
            steps = max(steps, i + nums[i]);
        }
        return steps >= (len-1);
    }
};
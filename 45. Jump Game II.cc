// TC: O(n)
// SC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        //The maximum index that can be reached according to the current number of jumps
        int idx_max = 0;
        //The next maximum index updates when index i is greater than idx_max.
        int idx_next = -1;
        //the number of jumps
        int jumps = 0;
        
        //base condition
        if (nums.size() == 1) {
            return 0;
        }
        
        for(int i = 0; i < nums.size(); i++){
            
            if(i > idx_max) {
                jumps++;
                swap(idx_max, idx_next);
            }
            
            idx_next = max(idx_next, i + nums[i]);
            
            
            if (idx_next >= nums.size() - 1) {
                jumps++;
                break;
            }
        }
        
        
        return jumps;
    }
};
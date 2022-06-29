//Using Cycle-Detection method
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        //phase 1:
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        //phase 2:
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
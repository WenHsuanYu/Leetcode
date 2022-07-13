// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        
        while (l <= r) {
            mid = l + ((r - l) >> 2);
            if (nums[mid] == target)
                return mid;
            
            if (nums[l] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[l]) {
                    //same side
                    r = mid - 1;
                } else {
                    //the other side
                    l = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
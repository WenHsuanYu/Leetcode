// TC: O(logn)
// SC: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
               l = mid + 1;
            } else {
               r = mid - 1;
            }
        }
        return l;
    }
};


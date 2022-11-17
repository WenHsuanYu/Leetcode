//TC: O(logn)
//SC: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l <= r && nums[mid] != target) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return nums[mid] == target ? mid : -1;
    }
};
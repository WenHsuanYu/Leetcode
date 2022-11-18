//Using two kinds of binary search
//TC: O(logn)
//SC: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) {
            return {-1,-1};
        }
        vector<int> res(2, -1);
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l == nums.size() || nums[l] != target) {
            return res;
        }
        res[0] = l;
        l = -1;
        r = nums.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        res[1] = l;
        return res;
    }
};
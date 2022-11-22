//TC: O(logn)
//SC: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        // int ans = 0;
        int l = -1;
        int r = nums.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (m != nums.size() - 1 && nums.at(m) > nums.at(m + 1)) {
                r = m; 
            } else {
                l = m;
            }
        }
        return r == nums.size() ? r - 1 : r;
    }
};

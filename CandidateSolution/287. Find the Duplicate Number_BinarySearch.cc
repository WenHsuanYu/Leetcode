//Using Binary Search
//TC: O(nlogn)
//SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto find = [&](int cur) {
            int count = 0;
            for (auto &i: nums) {
                if (i <= cur)
                    count++;
            }
            return count++;
        };
        
        int left = 0;
        int right = nums.size();
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (find(mid) > mid) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
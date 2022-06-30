//Using Robinson-Schensted-Knuth algorithm
//TC:O(nlogn)
//SC:O(n)
class Solution {
public:     
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tail;
        tail.push_back(nums[0]);
        //if (nums.size() == 0)
        // return 0;
        //length >= 1
        for (int i = 1; i < n; i++) {
            if (nums[i] > tail.back())
                tail.push_back(nums[i]);
            else {
                *lower_bound(tail.begin(), tail.end(), nums[i]) = nums[i];
            }
        }
        return tail.size();
    }
};
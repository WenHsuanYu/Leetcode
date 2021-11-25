//Runtime: 37 ms, faster than 24.80% of C++ online submissions for Rotate Array.
//Memory Usage: 24.9 MB, less than 92.15% of C++ online submissions for Rotate Array.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return;
        
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
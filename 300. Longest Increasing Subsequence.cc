// O(nlogL), where L is the length of LIS
// O(L)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int l = 0;
            int r = res.size() - 1;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (res[m] < nums[i]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            if (res.empty() || res[l] < nums[i]) {
                res.push_back(nums[i]);
            } else {
                res[l] = nums[i];
            }  
        }
        return res.size();
    }
};
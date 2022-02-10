class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty() || (nums.size() == 1 && nums[0] == 0))
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        //End the loop when it iterates to n-2
        for (int k = 0; k < nums.size() - 2; k++) {
            //After sorting, fixing a positive number have no solution. 
            if (nums[k] > 0)
                break;
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int target = 0 - nums[k];
            int i = k + 1;
            int j = (int)nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[i + 1])
                        i++;
                    while(i < j && nums[j] == nums[j - 1])
                        j--;
                    i++;
                    j--;
                } else if (nums[i] + nums[j] < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return ans;
    }
};
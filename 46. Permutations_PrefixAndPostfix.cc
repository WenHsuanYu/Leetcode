// TC: O(n!)
// SC: O(n!)
// Solution:
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return vector<vector<int>> (1, vector<int>());
        vector<vector<int>> ans;
        int first = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> element = permute(nums);
        
        for (auto &e : element) {
            for (int j = 0; j <= e.size(); j++) {
                e.insert(e.begin() + j, first);
                ans.push_back(e);
                e.erase(e.begin() + j);
            }
        }
        
        return ans;
    }

};




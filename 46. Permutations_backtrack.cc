class Solution {
// TC: O(n * n!)
// SC: O(n)
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int>& nums, int index) {
        
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        
        for (int i = index; i < nums.size(); ++i) {
            swap(nums[index], nums[i]);
            backtrack(nums, index + 1);
            swap(nums[index], nums[i]);
            
        }
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        backtrack(nums, 0);
        
        return res;
        
    }
};
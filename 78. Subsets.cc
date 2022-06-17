//using backtracking method
//TC: O(2^N)
//SC: O(N)
class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int> &nums, int i, vector<int> temp)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        backtrack(nums, i+1, temp);
        temp.push_back(nums[i]);
        backtrack(nums, i+1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;       
        backtrack(nums, 0, temp);
        return ans;
    }
};
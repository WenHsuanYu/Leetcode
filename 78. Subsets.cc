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

// or another implementation
class Solution {
public:
    vector<vector<int>> res_vec = {{}};
    vector<int> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res_vec;
    }
    void dfs(int idx, vector<int> &nums) {
        for (int i = idx; i < nums.size(); ++i) {
            res.push_back(nums[i]);
            res_vec.push_back(res);
            dfs(i+1, nums);
            res.pop_back();
        }
    }
};
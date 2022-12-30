// TC: O(n!)
// SC: O(n)
class Solution {
public:
    vector<int> temp, visited;
    vector<vector<int>> res;
    
    void dfs(vector<int>& nums, int level) {
        
        if (level == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == true)
                continue;   
            
            visited[i] = 1;
            temp.push_back(nums[i]);
            dfs(nums, level + 1);
            temp.pop_back();
            visited[i] = 0; 
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size(), 0);
        dfs(nums, 0);
        
        
        return res;
    }
};
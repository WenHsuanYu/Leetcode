// TC: O(n!)
// SC: O(n)
class Solution {
public:
    vector<int> tmp;
    vector<int> visited;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size(), 0);
        dfs(nums);
        return res;
    }
    void dfs(vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums);
            visited[i] = 0;
            tmp.pop_back();
        }
    }
};
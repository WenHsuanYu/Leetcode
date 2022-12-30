// TC: O(n^m), where n is the number of candidates and m is the target
// SC: O(m)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return res;
    }

private:
    void dfs(int idx, vector<int>& candidates, int target) {
        if (target <= 0) {
            if (!target) {
                res.push_back(tmp);
            }
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            dfs(i, candidates, target - candidates[i]);
            tmp.pop_back();
        }
    }

};
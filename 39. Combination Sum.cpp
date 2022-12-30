// TC: O(n^m), where n is the number of candidates and m is the target
// SC: O(m)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    
    void recur(vector<int>& candidates, int target, int i) {
            if (target < 0) {
                return;
            }
            
            if (target == 0) {
                result.push_back(temp);
                return;
            }
            
            while (i < candidates.size() && target - candidates[i] >= 0) {
                temp.push_back(candidates[i]);
                recur(candidates, target - candidates[i], i);
                ++i;
                temp.pop_back();
                
            }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        recur(candidates, target, 0);
        return result;
    
    }
};
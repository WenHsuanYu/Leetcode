// TC: O(k * 2^n'), where n' is the number of calling recursions of every element, and every element calls itself value in every recursion, and these calling # plus length of elements adds up to n'
// SC: O(ceil(target / candidates[0]))
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
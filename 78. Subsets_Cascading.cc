//using Cascading method
//TC: O(N*2^N)
//SC: O(N*2^N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        vector<int> ele;
        int subset_size;
        for (auto value : nums) {
            subset_size = subsets.size();
            for (int i = 0; i < subset_size; i++) {
                ele = subsets[i];
                ele.push_back(value);
                subsets.push_back(ele);
            }
        }
        return subsets;
        
    }
};
//using Cascading method
//TC: O(N*2^N), where n is the number of nums
//SC: O(N*2^N) because we keep N elements for each subset
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
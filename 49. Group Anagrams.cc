class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            um[strs[i]].push_back(temp);
        }
                
        vector<vector<string>> ans;
        ans.reserve(um.size());
        
        for (auto &[key, value]: um)
            ans.push_back(value);
        return ans;

    }
};
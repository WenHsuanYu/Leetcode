// TC: O(nlogn * str[i].length), where str[i].length is between 0 and 100
// SC: O(n) 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (const auto&s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            um[key].push_back(s);
        }
                
        vector<vector<string>> ans;
        ans.reserve(um.size());
        
        for (auto &[key, value]: um)
            ans.push_back(value);
        return ans;

    }
};
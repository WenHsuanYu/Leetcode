// using hash table method
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        int n = nums.size();
        for (auto &i : nums) {
            umap[i]++;
            if (umap[i] > (n >> 1))
                return i;
        }
        return -1;
    }
};
//Using hash table method
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int ans = 0;
        int sum = 0;
        //handle `sum` exactly equal to `k` 
        umap[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int difference = sum - k;
            if (umap.find(difference) != umap.end()) {
                ans += umap[difference];
            }
            umap[sum]++;
        }
        return ans;
    }
};
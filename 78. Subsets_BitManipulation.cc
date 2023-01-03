//using bit manipulation method
//TC: O(2^N * N)
//SC: O(N)
#define bitmask_len 11

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int sub = pow(2, n);
        vector<vector<int>> res(sub, vector<int>());
        int idx = 0;
        while (idx < sub) {
            string bitmask = bitset<bitmask_len>(idx).to_string();

            for (int j = bitmask_len - n; j < bitmask_len; j++) {
                if (bitmask[j] == '1') {
                    res[idx].push_back(nums[j - bitmask_len + n]);
                }
            }
            ++idx;
        }
        return res;
    }
};

/* Alternative method:
 * Using bit manipulation method
 * TC: O(2^N * N)
 * SC: O(N)
 * class Solution {
 * public:
 *     vector<vector<int>> subsets(vector<int>& nums) {
 *         vector<vector<int>> ans;
 *         int n = nums.size();
 *         int sub = pow(2, n);
 *         int i = 0;
 *        while (i < sub) {
 *            vector<int> temp;
 *            for (int j = 0; j < n; ++j) {
 *                if (i & (1 << j)) {
 *                    temp.push_back(nums[j]);
 *                }
 *             }
 *             ans.push_back(temp);
 *              ++i;
 *         }
 *        return ans;
 *    }
 * };
**/

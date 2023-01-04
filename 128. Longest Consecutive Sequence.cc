// TC: O(n)
// SC: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> uset(begin(nums), end(nums));
        int n = nums.size();
        int longestSequence = 0;
        for (auto &val : uset) {
            //C++20 can use uset.contains(key)
            if (uset.count(val - 1))
                continue;
            int j = 1;
            while (uset.count(val + j))
                j++;
            longestSequence = max(j, longestSequence);
        }        
        
        return longestSequence;
    }
};
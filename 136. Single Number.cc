//using bit manipulation xor operator for this problem
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums) {
            ans ^= i;
        }
        return ans;
    }
};
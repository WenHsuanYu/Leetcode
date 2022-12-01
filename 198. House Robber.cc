//using dp concept without memorization 
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int odd = 0;
        int even = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
               //wanna rob houses with an even number, but it have to compare the total money of odd to even plus nums[i]
               even = max(even + nums[i], odd);
            } else {
                odd = max(odd + nums[i], even);
            }
        }
        return max(even, odd);
    }
};
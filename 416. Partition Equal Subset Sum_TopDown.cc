//Using Dp method
//TC: O(n * sum), where sum is a half of sum of 'nums'
//SC: O(sum)
class Solution {
public:
    bool Subset(vector<int>& nums, int sum, vector<int>& dp, int i = 0) {
        if (sum == 0)
            return true;
        if (i >= size(nums) || sum < 0)
            return false;
        if (dp[sum] != -1)
            return dp[sum];
                        //pick or not
        return dp[sum] = Subset(nums, sum - nums[i], dp, i + 1) || Subset(nums, sum, dp, i + 1);
    }

    bool canPartition(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum & 1)
            return false;
        //Achievable or not
        vector<int> dp(totalSum / 2 + 1, -1);
        return Subset(nums, totalSum / 2, dp);
    }
};

/* 2D vector */
/*
* class Solution {
* public:
*     int8_t dp[201][10001] = {[0 ... 200] = {[0 ... 10000] = -1}};  
*     bool canPartition(vector<int>& nums) {
*         int totalSum = accumulate(begin(nums), end(nums), 0);
*         if(totalSum & 1) return false;
*         return subsetSum(nums, totalSum / 2);
*     }
*     bool subsetSum(vector<int>& nums, int sum, int i = 0) {
*         if(sum == 0) return true;
*         if(i >= size(nums) || sum < 0) return false; 
*         if(dp[i][sum] != -1) return dp[i][sum];
*         return dp[i][sum] = subsetSum(nums, sum - nums[i], i + 1) || subsetSum(nums, sum, i + 1);
*     }
* };
*/
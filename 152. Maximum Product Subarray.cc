//TC: O(n)
//SC: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int min_product = nums[0];
        int max_product = nums[0];
        for (int i = 1; i < n; i++) {
            
            if (nums[i] < 0)
                swap(min_product, max_product);
            max_product = max(nums[i], nums[i] * max_product);
            min_product = min(nums[i], nums[i] * min_product);
            ans = max(ans, max_product);
        }
        
        return ans;
    }
};
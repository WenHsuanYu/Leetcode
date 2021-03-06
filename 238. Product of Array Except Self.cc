//Using Prefix and Suffix concept method
//TC:O(n)
//SC:O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for (int i = 1; i < n; i++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }
                
        for (int i = n - 1, SuffixProduct = 1; i >= 0; i--) {
            ans[i] = ans[i] * SuffixProduct;
            SuffixProduct = SuffixProduct * nums[i];
        }
        
        return ans;   
    }
};
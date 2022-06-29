//Using bit manipulation method
//TC: O(nlogn)
//SC: O(1)
class Solution {
public:
    int calc(int max_num) {
        int bits = 0;
        while (max_num > 0) {
            max_num /= 2;
            bits++;
        }
        return bits;
    }
    
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        int n = nums.size() - 1;
        int max_num = *max_element(nums.begin(), nums.end());
        int max_bit = calc(max_num);
        
        for (int bit = 0; bit < max_bit; bit++) {
            int mask = (1 << bit);
            int base_binary = 0;
            int nums_binary = 0;
            
            for (int i = 0; i <= n; i++) {
                // 0 & 1
                if (i & mask) {
                    base_binary++;
                }
                
                if (nums[i] & mask) {
                    nums_binary++;
                }
                
            }
            
            if (nums_binary > base_binary)
                ans |= mask;
        }
        return ans;
    }
};
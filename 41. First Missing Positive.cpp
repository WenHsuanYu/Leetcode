// TC: O(n)
// SC: O(1)
static auto num = []{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 1 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            // abs is used to index keep the index positive
            int index = abs(nums[i]);
            //Considering number [1,n], if nums[i] is within range [1,n], the number of the index (num[i] - 1) multiply -1 (as marked)
            if (index >= 1 && index <= n) {             
                nums[index - 1] = -1 * abs(nums[index - 1]);
            }
        }


        for  (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};
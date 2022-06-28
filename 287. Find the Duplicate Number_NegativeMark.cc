//Using Negative mark method
//TC: O(n)
//SC: O(1)
//Violating the constraint that the element cannot be modified
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]);
            if (nums[index] < 0) {
                ans = index;
                break;
            }
            nums[index] *= -1;
        }
        //Note that: restore modified nums
        for (auto& num : nums) {
            num = abs(num);
        }
        return ans;
    }
};
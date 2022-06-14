//using DNF sort method
//TC: O(n), SC: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int start = 0;
        int high = nums.size() - 1;
        while (start <= high) {
            switch(nums[start]) {
                case 0:
                    swap(nums[low++], nums[start++]);
                    break;
                case 1:
                    start++;
                    break;
                case 2:
                    swap(nums[high--], nums[start]);
                    break;
            }
        }
    }
};
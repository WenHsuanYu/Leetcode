//using DNF sort method
//TC: O(n), SC: O(1)
//The value is 0 from index 0 to index low -1
//The value is 1 from index low to index high
//The value is 2 from index high + 1 to end 
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
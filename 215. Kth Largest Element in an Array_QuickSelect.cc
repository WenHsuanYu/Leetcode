//Using QuickSelect method
//TC: O(n) in average case & O(n^2) in worst case
//SC: O(1)
class Solution {
public:
    int QuickSelect(vector<int>& nums, int left, int right, int k) {
        while(left <= right) {

            int pivot = right;
            int index = left;

            for (int i = left; i <= right; i++) {
                if (nums[i] < nums[pivot]) {
                    swap(nums[i], nums[index]);
                    index++;
                }
            }
            swap(nums[pivot], nums[index]);

            if (index == k)
                return nums[index];
            else if(k > index)
                left = index + 1;
            else
                right = index - 1;
        }
        return -1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        return QuickSelect(nums, 0, nums.size() - 1, target);
    }
};
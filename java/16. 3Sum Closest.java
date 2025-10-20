//16. 3Sum Closest
// TC: O(N^2) where N = nums.length
// SC: O(1)

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        
        int low = 0, high = nums.length - 1;
        while (low + 1 < high - 1 && nums[low + 1] + nums[high] + nums[high - 1] < target) { // prune left side
            low++;
        }
        while (high - 1 > low + 1 && nums[low] + nums[low + 1] + nums[high - 1] > target) { // prune right side
            high--;
        }
        
        int l = low;
        int closest = nums[low] + nums[low + 1] + nums[low + 2];
        
        while (l < high - 1) {
            int left = l + 1;
            int right = high;
            
            while (left < right) { 
                int sum = nums[l] + nums[left] + nums[right];
                
                if (sum == target) return target;
                
                if (Math.abs(sum - target) < Math.abs(closest - target))
                    closest = sum;

                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
            l++;
        }
        return closest;
    }
}




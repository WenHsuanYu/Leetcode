// 977. Squares of a Sorted Array
// TC: O(N) where N = nums.length
// SC: O(1) excluding the output array

class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int left = 0, right = n - 1, pos = n - 1;
    
        while (left <= right) {
            if (Math.abs(nums[left]) > Math.abs(nums[right])) {
                res[pos--] = nums[left] * nums[left];
                left++;
            } else {
                res[pos--] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
}
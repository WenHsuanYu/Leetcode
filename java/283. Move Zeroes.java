// 283. Move Zeroes
// TC: O(N) where N = nums.length
// SC: O(1)

class Solution {


    public static void moveZeroes(int[] nums) {
        if (nums.length <= 1)
            return;

        for (int nonzero = 0, i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                swap(nums, nonzero++, i);
            }
        }
    }

    public final static void swap(int[] nums, int left, int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
}
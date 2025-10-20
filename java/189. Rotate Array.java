// 189. Rotate Array
// TC: O(N) where N = nums length
// SC: O(1)

class Solution {
    public void rotate(int[] nums, int k) {
        int pending_element = nums.length;
        int finished_element = 0;
        int first = 0;
        int second = 0;
        while (pending_element > 0 && (k %= pending_element) >= 1) {
            for (int i = 0; i < k; i++) {
                //swap
                first = i + finished_element;
                second = pending_element + finished_element - k + i;
                nums[first] ^= nums[second];
                nums[second] ^= nums[first];
                nums[first] ^= nums[second];
            }
            finished_element += k;
            pending_element -= k;
        }
    }
}
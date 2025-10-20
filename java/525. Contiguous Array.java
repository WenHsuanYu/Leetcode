//525. Contiguous Array
// TC: O(N) where N = nums.length
// SC: O(N) for the hash map
class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, -1);
        int count = 0;
        int maxlength = 0;
        for (int i = 0; i < nums.length; i++) {
            count += nums[i] == 0 ? -1 : 1;
            if (m.containsKey(count)) {
                maxlength = maxlength > i - m.get(count) ? maxlength : i - m.get(count); 
            } else {  //add value of prefix sum first time 
                m.put(count, i);
            }
        }
        return maxlength;

    }
}
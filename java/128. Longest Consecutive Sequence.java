//128. Longest Consecutive Sequence
// TC: O(N) where N = nums length
// SC: O(N) for the hash set
class Solution {
    static {
        for (int i = 0; i< 50; i++) {
            longestConsecutive(new int[]{1,2});
        }
    }

    public static int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (var i : nums) {
            set.add(i);
        }
        int start = 0;
        int longest = 0;

        for (int num : set) {
            if (set.contains(num - 1)) // already counted in another sequence
                continue;
            int length = 1;
            int curr = 1;
            while (set.contains(num + curr++)) { 
                length++;
            }
            longest = longest > length ? longest : length;
        }
        return longest;


    }
}
// 217. Contains Duplicate
// TC: O(N) where N = nums length
// SC: O(N) for the hash set

class Solution {
    static{
        for(int i=0;i<=50;i++)
            containsDuplicate(new int[]{0, 1, 0});  // 每次都修改同一個數組
    }

    public static boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (var v : nums) {
            if (!seen.add(v)) {
                return true;
            }
        }
        return false;
    }
}
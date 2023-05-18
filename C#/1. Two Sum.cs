public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        int size = nums.Length;
        for (int i = 0; i < size; i++)
        {
            if (dict.ContainsKey(nums[i])) 
            {
                return new int[] {i, dict[nums[i]]};
            }
            else
            {
                dict.TryAdd(target - nums[i], i);
            }
        }
        return new int[] {-1, -1};
    }
}
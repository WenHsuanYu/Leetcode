// TC: O(n^2)
// SC: O(1)
public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        int len = nums.Length;
        Array.Sort(nums);
        // diff = sum - target
        int diff = Int32.MaxValue;
        for (int i = 0; i < len -2; i++)
        {
            int j = i + 1;
            int k = len - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (Math.Abs(sum - target) < Math.Abs(diff))
                    diff = sum - target;
                if (sum < target)
                    j++;
                else
                    k--;
            }
            if (diff == 0)
                break;
        }
        return diff + target;
    }
}
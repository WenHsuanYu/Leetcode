// Not Sorting method
// TC: O(mn)
// SC: O(n)
public class Solution {
    bool check(int[] arr) {
        int min = Int32.MaxValue;
        int max = Int32.MinValue;
        HashSet<int> hashSet = new HashSet<int>();

        foreach (int num in arr)
        {
            min = Math.Min(min, num);
            max = Math.Max(max, num);
            hashSet.Add(num);
        }

        if ((max - min) % (arr.Length - 1) != 0)
        {
            return false;
        }
        int diff = (max - min) / (arr.Length - 1);
        int curr = min + diff;

        while (curr < max)
        {
            if (!hashSet.Contains(curr))
                return false;
            curr += diff;
        }
        return true;
    }


    public IList<bool> CheckArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<bool> result = new List<bool>();
        int len = l.Length;
        for (int i = 0; i < len; i++)
        {
            int[] sequence = new int[r[i] - l[i] + 1];
            Array.Copy(nums, l[i], sequence, 0, r[i] - l[i] + 1);
            result.Add(check(sequence));
        }
        return result;
    }
}
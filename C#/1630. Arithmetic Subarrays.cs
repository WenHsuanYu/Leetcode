public class Solution {
    public IList<bool> CheckArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<bool> result = new List<bool>();
        int len = l.Length;
        for (int i = 0; i < len; i++)
        {
            int[] sequence = new int[r[i] - l[i] + 1];
            Array.Copy(nums, l[i], sequence, 0, r[i] - l[i] + 1);
            Array.Sort(sequence);
            int j;
            for(j = 0; j < sequence.Length - 2; j++)
            {
                if (sequence[j + 1] - sequence[j] != sequence[j + 2] - sequence[j + 1])
                {
                    result.Add(false);
                    break;
                }
            }
            if (j == sequence.Length - 2)
                result.Add(true);
        }
        return result;
    }
}
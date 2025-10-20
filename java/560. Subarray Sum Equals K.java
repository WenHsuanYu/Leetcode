//560. Subarray Sum Equals K
// TC: O(N) where N = nums.length
// SC: O(N) for the hash map

class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> m = new HashMap<>(); // <sum, frequency>
        m.put(0, 1);
        int count = 0;
        int sum = 0;
        for (int val : nums) {
            sum += val;
            count += m.getOrDefault(sum - k, 0);
            m.put(sum, m.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}


// TC: O(N) where N = nums.length
// SC: O(N) for the hash map
class Solution {
    private static final int NULL = Integer.MIN_VALUE;
    private static final int MIXER = 0x9E3779BA;
    
    public static int subarraySum(int[] nums, final int k) {
        final int mask = mask(nums.length);
        final int[] hashtable = new int[mask + 1];
        int res = 0, sum = 0, zeros = 1;
        
        for (final int n : nums) {
            sum += n;
            final int diff = sum - k;
            
            if (diff != 0) {
                int i = diff * MIXER & mask;
                while (true) {
                    final int key = hashtable[i];
                    if (key == 0) break;
                    if (key == diff) {
                        res += hashtable[i + 1];
                        break;
                    }
                    i = i + 2 & mask;
                }
            } else {
                res += zeros;
            }
            
            if (sum != 0) {
                int i = sum * MIXER & mask;
                while (true) {
                    final int key = hashtable[i];
                    if (key == 0) {
                        hashtable[i] = sum;
                        hashtable[i + 1] = 1;
                        break;
                    }
                    if (key == sum) {
                        hashtable[i + 1]++;
                        break;
                    }
                    i = i + 2 & mask;
                }
            } else {
                zeros++;
            }
        }
        return res;
    }
    
    public static int mask(int n) {
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return (n << 1) | 31;
    }
}
// TC: O(N log N) for sorting + O(N) for merging = O(N log N) overall, where N is the number of intervals
// SC: O(1) excluding the space for output
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> res = new ArrayList<>();
        
        for (int[] interval : intervals) {
            if (res.isEmpty() || res.get(res.size() - 1)[1] < interval[0]) {
                res.add(interval);  // 不重疊，添加新區間
            } else {
                res.get(res.size() - 1)[1] = Math.max(res.get(res.size() - 1)[1], interval[1]);  // 重疊，合併
            }
        }
        
        return res.toArray(new int[res.size()][]);
    }

}
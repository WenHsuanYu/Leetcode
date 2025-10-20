// 57. Insert Interval
// TC: O(n)
// SC: O(n)
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int row = intervals.length;
        int i = 0;
        List<int[]> res = new ArrayList<>();
        int inserted_index = 0;
        for (; i < row; i++) {
            if (newInterval[0] > intervals[i][1]) {
                ++inserted_index;
                res.add(intervals[i]);
            } else if (newInterval[1] >= intervals[i][0]) {
                newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
                newInterval[1] = newInterval[1] > intervals[i][1] ? newInterval[1] : intervals[i][1];
            } else {
                res.add(intervals[i]);
            }
        }
        res.add(inserted_index, newInterval);
        return res.toArray(new int[res.size()][]);
    }
}

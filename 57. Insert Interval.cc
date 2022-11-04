//TC: O(row)
//SC: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int row = intervals.size();
        vector<vector<int>> res;
        int curr = 0;
        for (int i = 0; i < row; i++) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                ++curr;
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.insert(res.begin() + curr, newInterval);
        return res;
    }
};
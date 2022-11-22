//Using Binary Search method
//O(log(m + n))
//O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(false);
        int col = matrix[0].size();
        int len = matrix.size() * col;
        int l = 0;
        int r = len;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (matrix[m / col][m % col] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return (l != len && matrix[l / col][l % col] == target) ? true : false;
    }
};
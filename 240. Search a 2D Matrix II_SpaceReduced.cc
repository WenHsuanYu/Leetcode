// TC: O(m + n)
// SC: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;
        while(row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (target > matrix[row][col])
                row++;
            else
                col--;
                
        }
        return false;
    }
};
//T.C: O(mn)
//S.C: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            auto it = find(matrix[i].begin(), matrix[i].end(), target);
            if (it != matrix[i].end()) {
                return true;
            }
        }
        
        return false;
    }
};
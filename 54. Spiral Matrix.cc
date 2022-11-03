//TC: O(mn)
//SC: O(1) ignore the result space
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();
        int up = 0;
        int down = row - 1;
        int left = 0;
        int right = col - 1;
        vector<int> res;
        res.reserve(row * col);
        while (true) {
            for (int j = left; j <= right; j++) {
                res.push_back(matrix.at(up).at(j));
            }
            up++;
            if (up > down)
                break;
            for (int j = up; j <= down; j++) {
                res.push_back(matrix.at(j).at(right));
            }
            right--;
            if (right < left)
                break;
            for (int j = right; j >= left; j--) {
                res.push_back(matrix.at(down).at(j));
            }
            down--;
            if (down < up)
                break;
            for (int j = down; j >= up; j--) {
                res.push_back(matrix.at(j).at(left));
            }
            left++;
            if (left > right)
                break;
        }
        
    
        return res;
    }
};
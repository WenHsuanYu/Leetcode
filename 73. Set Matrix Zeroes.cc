class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_col = false;
        int row = matrix.size();
        int col = matrix[0].size();
        
        // matrix[0][0] represents the first row
        // an additional variable "first_col" represents the first column
        for (int i = 0; i < row; ++i) {
            
            if (matrix[i][0] == 0)
                first_col = true;
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int i = 0; i < col; i++) {
                matrix[0][i] = 0;
            }
        }
        
        if (first_col) {
           for (int i = 0; i < row; i++) {
               matrix[i][0] = 0;
           } 
        }      
        
             
    }
};
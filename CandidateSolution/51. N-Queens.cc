class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> nQueens(n, string(n, '.'));
        solve_nQueens(ans, nQueens, 0, n);
        
        return ans;
    }
    
    
    void  solve_nQueens(vector<vector<string>> &ans, vector<string> &nQueens, int row, int &n) {
        if (row == n) {
            ans.push_back(nQueens);
            return;
        }
        
        
        for (int col = 0; col < n; col++) {
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solve_nQueens(ans, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<string> &nQueens, int row, int col, int &n) {
        //Check if this col have a 'Q'.
        for (int i = 0; i < row; ++i) {
            if (nQueens[i][col] == 'Q')
                return false;
        }
        //Check if the 45 degrees diagonal have a 'Q'
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (nQueens[i][j] == 'Q')
                return false;
        }
        //Check if the 135 degrees diagonal have a 'Q'
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (nQueens[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
};
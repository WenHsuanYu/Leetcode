#define attack 0
#define not_attack 1

class Solution {
public:
    
    vector<vector<string>> ans;
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> nQueens(n, string(n, '.'));
        vector<int> Line_col(n, not_attack);
        vector<int> diag_45(2 * n - 1, not_attack);
        vector<int> diag_135(2 * n - 1, not_attack);
        solveNQueens(nQueens, Line_col, diag_45, diag_135, 0, n);
        return ans;
    
    }
    
private:
    template<class S, class T, class V>
    void solveNQueens(S &nQueens, T &Line_col, T &diag_45, T &diag_135, V row, V &n) {
        if (row == n) {
            ans.push_back(nQueens);
            return;
        } 
        
        for (int col = 0; col < n; ++col) {
            if (Line_col[col] && diag_45[row + col] && diag_135[n - 1 + row - col]) {
                Line_col[col] = diag_45[row + col] = diag_135[n - 1 + row - col] = attack;
                nQueens[row][col] = 'Q';
                solveNQueens(nQueens, Line_col, diag_45, diag_135, row + 1, n);
                nQueens[row][col] = '.';
                Line_col[col] = diag_45[row + col] = diag_135[n - 1 + row - col] = not_attack;
            }
            
        }
        
    }
};
// TC: O(n^m), where n is the number of possibilities for each square and m is the number of spaces that are blank.
// SC: O(m)

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(valid(c, board, i, j)) {
                            board[i][j] = c;
                            if(solve(board) == true) 
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool valid(char c, vector<vector<char>>& board, int row, int col) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c || board[row][i] == c || board[3 * (row / 3) + (i / 3)][3  * (col / 3) + (i % 3)] == c) 
                return false;
        }
        return true;
    }
};
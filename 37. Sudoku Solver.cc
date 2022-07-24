struct Sudoku_board{
    short row[9];
    short col[9];
    short box[9];
    
    vector<vector<char>> &board;
    int empty_positions = 81;
    
    Sudoku_board(vector<vector<char>>& input): board(input) {
        for (int i = 0; i < 9; i++) {
            row[i] = col[i] = box[i] = 0;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;
                AddBit(i, j, board[i][j] - '0');
                
            }
        }
    }
    
    void AddBit(int x, int y, int val) {
        //insert a possible value if not exist
        board[x][y] = '0' + val;
        row[x] |= (1 << val);
        col[y] |= (1 << val);
        box[(x / 3) * 3 + (y / 3)] |= (1 << val);
        empty_positions--;
    }
    
    inline short candidates(int x, int y) {
        return row[x] | col[y] | box[(x / 3) * 3 + y / 3];
    }
    
    void clear_position(int x, int y) {
        int val = board[x][y] - '0';
        board[x][y] = '.';
        row[x] &= ~(1 << val);
        col[y] &= ~(1 << val);
        box[(x / 3) * 3 + y / 3] &= ~(1 << val);
        empty_positions++;
    }
    
};


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Sudoku_board handle_board(board);
        backtrack(handle_board);
    }
    
    void backtrack(Sudoku_board &board) {
        if (!board.empty_positions) {
            return;
        }
        
        int startX = -1;
        int startY = -1;
        int possibilities = 9;
        // find a position from least to most possible values
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++) {
                if(board.board[i][j] != '.') {
                    continue;
                }
                
                const short used_mask = board.candidates(i, j);
                short diff = 9 - __builtin_popcount(used_mask);
                if (diff < possibilities) {
                    possibilities = diff;
                    startX = i;
                    startY = j;
                }
                
            }
        }
        
        const short used_mask = board.candidates(startX, startY);
        
        for (int val = 1; val <= 9; val++) {
            if (used_mask & (1 << val)) {
                continue;
            }
            
            board.AddBit(startX, startY, val);
            backtrack(board);
            // Stop searching... A unique solution is guaranteed.
            if (board.empty_positions == 0) {
                return;
            }
            board.clear_position(startX, startY);
        }
        
    }
};
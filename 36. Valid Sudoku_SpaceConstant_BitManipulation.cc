// Using bit manipulation
// TC: O(9 * 9)
// SC: O(9 * 3)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        static short row[9];
        static short col[9];
        static short square[9];
        
        for (int i = 0; i < 9; i++) {
            row[i] = col[i] = square[i] = 0;
        }
        
        bool result = true;
        auto AddBit = [&](int x, int y, int val){
            if (row[x] & (1 << val)) {
                return false; 
            } else {
                row[x] |= (1 << val);
            }
            
            if (col[y] & (1 << val)) {
                return false;
            } else {
                col[y] |= (1 << val);
            }
            
            if (square[x / 3 * 3 + y / 3] & (1 << val)) {
                return false;
            } else {
                square[x / 3 * 3 + y / 3] |= (1 << val);
            }
            return true;
        };
        
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    result = AddBit(i, j, board[i][j] - '0');
                    if (result == false) {
                        return result;
                    }
                }
            }
        }
        return true;
        
    }
};